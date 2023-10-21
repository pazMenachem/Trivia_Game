using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClientTrivia
{
    /// <summary>
    /// Represents a DataSender responsible for sending data to a socket.
    /// </summary>
    internal class DataSender
    {
        private readonly Socket _sock; // The socket used for sending data
        private byte _code; // The code to be sent
        private string _msg; // The message to be sent
        private byte[] _dataToSend; // The data to be sent as a byte array

        /// <summary>
        /// Initializes a new instance of the DataSender class with the specified socket.
        /// </summary>
        /// <param name="sock">The socket to use for sending data.</param>
        public DataSender(Socket sock) => _sock = sock;

        /// <summary>
        /// Sets the data to be sent.
        /// </summary>
        /// <param name="code">The code to be sent.</param>
        /// <param name="msg">The message to be sent.</param>
        public void SetDataToSend(byte code, string msg)
        {
            this._code = code;
            this._msg = msg;
            ConvertMsg();
        }

        /// <summary>
        /// Sends the data to the socket.
        /// </summary>
        public void SendData()
        {
            try
            {
                _sock.Send(_dataToSend);

                Console.WriteLine("Sent data to the server."
                                  + "\nMessage - " + _msg);

            }
            catch (SocketException ex)
            {
                Console.WriteLine($"Error sending data: {ex.Message}");
                MessageBox.Show($"Error sending data: {ex.Message}",
                                "Alert",
                                MessageBoxButtons.OK,
                                MessageBoxIcon.Warning);
                Environment.Exit(0);
            }
        }
        private void ConvertMsg()
        {
            int msgSize = _msg.Length;

            // Convert _code to a byte
            byte byteCode = (byte)_code;

            // Convert msgSize to 4 bytes (int)
            byte[] sizeBytes = BitConverter.GetBytes(msgSize);
            Array.Reverse(sizeBytes);

            byte[] msgBytes = Encoding.UTF8.GetBytes(_msg);

            // Concatenate _code, 4-byte msgSize, and _msg
            _dataToSend = new byte[5 + _msg.Length];

            _dataToSend[0] = byteCode;
            sizeBytes.CopyTo(_dataToSend, 1);
            msgBytes.CopyTo(_dataToSend, 5);
        }
    }
}
