// Ignore Spelling: json

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Threading;

namespace ClientTrivia
{
    internal class Communicator
    {
        private readonly Socket _socket;
        private readonly DataSender _sender;
        private readonly DataReceiver _receiver;

        private static Communicator _instance;
        public static string UserName { get; set; }

        public static Communicator GetInstance()
        {
            if (_instance == null)
                _instance = new Communicator();
            return _instance;
        }

        public async Task<dynamic> SendAndReceiveData(byte code, dynamic jsonData = null) {
            _sender.SetDataToSend(code, JsonConvert.SerializeObject(jsonData));
            _sender.SendData();
            return await _receiver.ReceiveData();
        }

        public void SendData(byte code, dynamic jsonData = null)
        {
            _sender.SetDataToSend(code, JsonConvert.SerializeObject(jsonData));
            _sender.SendData();
        }

        public async Task<dynamic> ReceiveData(CancellationToken cancelToken)
        {
            return await _receiver.ReceiveData(cancelToken);
        }

        private Communicator()
        {
            _socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            ConnectToServer();

            _sender = new DataSender(_socket);
            _receiver = new DataReceiver(_socket);
        }

        private void ConnectToServer()
        {
            try
            {
                IPAddress ipAddress = IPAddress.Parse(Utils.ServerIP);
                IPEndPoint remoteEndPoint = new IPEndPoint(ipAddress, Utils.ServerPort);

                _socket.Connect(remoteEndPoint);
                Console.WriteLine("Connected to the server.");
            }
            catch (SocketException ex)
            {
                Console.WriteLine($"Error connecting to the server: {ex.Message}");
            }
        }
    }
}
