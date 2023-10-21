using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Drawing.Text;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;


namespace ClientTrivia
{
    /// <summary>
    /// DataReceiver class is responsible for receiving data from a connected socket.
    /// </summary>
    internal class DataReceiver
    {
        private readonly Socket _sock; // The connected socket used for data reception.
        private readonly byte[] _code = new byte[1]; // Buffer to store the received code.
        private readonly byte[] _msgSizeInBytes = new byte[4]; // Buffer to store the received message size.
        private byte[] _msgInBytes; // Buffer to store the received message data.
        private int _bytesRead; // Variable to track the number of bytes read during reception.
        private readonly NetworkStream _streamer;

        /// <summary>
        /// Initializes a new instance of the DataReceiver class with the specified socket.
        /// </summary>
        /// <param name="sock">The connected socket for data reception.</param>
        public DataReceiver(Socket sock){
            _sock = sock;
            _streamer = new NetworkStream(sock);
        }

        /// <summary>
        /// Receives data from the connected socket and deserializes it into Json object.
        /// </summary>
        /// <returns>Json object containing the received data.</returns>
        /// 
        public async Task<dynamic> ReceiveData(CancellationToken cancelToken = default(CancellationToken))
        {
            try
            {
                // Receiving Code
                _bytesRead = await _streamer.ReadAsync(_code, Utils.ZeroOffSet, Utils.CodeSize, cancelToken);
                if (cancelToken.IsCancellationRequested) return null;
                if (_bytesRead != 1) throw new Exception("Error receiving code");

                // Receiving message length
                await _streamer.ReadAsync(_msgSizeInBytes, Utils.ZeroOffSet, Utils.IntSize,cancelToken);

                // Set Message Array size
                _msgInBytes = new byte[BitConverter.ToInt32(_msgSizeInBytes, Utils.ZeroOffSet)];

                // Receive message
                await _streamer.ReadAsync(_msgInBytes, Utils.ZeroOffSet, _msgInBytes.Length, cancelToken);

                Console.WriteLine("Received Data : " + Encoding.UTF8.GetString(_msgInBytes));

                return JsonConvert.DeserializeObject(Encoding.UTF8.GetString(_msgInBytes));
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error receiving data: {ex.Message}");
                return null;
            }
        }
    }
}
