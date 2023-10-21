// Ignore Spelling: Utils

using System;
using System.Collections.Generic;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Text;
using System.Runtime.InteropServices;

namespace ClientTrivia
{
    public struct GameData
    {
        public string _RoomName;
        public int _TimeQuestion;
        public int _AmountOfQuestions;
        public int _MaxUsers;
        public int _roomId;
        public bool _owner;
        public string _creator;
        public string[] _playerNames;
    }

    public struct Question
    {
        public string _Question;
        public string _AnswerOne;
        public string _AnswerTwo;
        public string _AnswerThree;
        public string _AnswerFour;
        public string _CorrectAnswer;
    }
    
    public static class Utils
    {
        // BYTES
        public const int CodeSize = 1;
        public const int IntSize = 4;
        public const int ZeroOffSet = 0;

        // Codes
        public enum Codes
        {
            Error              = 0,
            Success            = 1,
            SignUp             = 102, // Request Codes 100 - 130
            LogIn              = 103,
            LogOut             = 104,
            JoinRoom           = 105,
            CreateRoom         = 106,
            GetRoomsData       = 107,
            GetPlayersInRoom   = 108,
            GetHighScore       = 109,
            GetStatistics      = 110,
            CloseRoom          = 111,
            StartGame          = 112,
            GetRoomState       = 113,
            LeaveRoom          = 114,
            ChatMessage        = 115,
            SubmitAnswer       = 116,
            LeaveGame          = 117,
            GetGameStats       = 118,
            CloseGame    	   = 119,
            UnValidCode        = 100, // Error Codes 50 - 80 *In the server side
            NotRelevant        = 101,
            BCPlayerJoinedLeft = 200, // BroadCast Codes 200 - 210
            BCNewChatMessage   = 201,
            BCGameStarted      = 202,
            BCRoomClosed       = 203,
            BCGameClosed       = 204,
        }
        // Error Codes
        // Connection const
        public const string ServerIP = "127.0.0.1"; // Localhost IP address
        public const int ServerPort = 8826; // Port number

        // Media
        // *TODO*
        // need to add the music into the project file
        private static readonly string path = "C:\\Users\\Paz_m\\source\\repos\\Magshimim_Trivia\\ClientTrivia\\Properties\\M.O.O.N - Dust (Synthwave).wav";
        public static System.Media.SoundPlayer player = new System.Media.SoundPlayer(path);

        // Misc
        public static PrivateFontCollection pfc = new PrivateFontCollection();

        static Utils()
        {
            LoadFont();
        }
        static private void LoadFont()
        {
            //Select your font from the resources.
            int fontLength = Properties.Resources.upheavtt.Length;

            //// create a buffer to read in to
            byte[] fontdata = Properties.Resources.upheavtt;

            //// create an unsafe memory block for the font data
            System.IntPtr data = Marshal.AllocCoTaskMem(fontLength);

            //// copy the bytes to the unsafe memory block
            Marshal.Copy(fontdata, 0, data, fontLength);

            //// pass the font to the font collection
            pfc.AddMemoryFont(data, fontLength);
        }

        public static void FillAllFieldsAlert()
        {
                MessageBox.Show("Please fill all the fields.",
                                "Alert",
                                MessageBoxButtons.OK,
                                MessageBoxIcon.Warning);
        }

        public static bool CheckForFields(params string[] fields)
        {
            foreach (string field in fields)
                if (String.IsNullOrWhiteSpace(field))
                    return false;
            return true;
        }

        public static void SwapForms<TFrom, TTo>(TFrom fromForm, params object[] args)
            where TFrom : Form
            where TTo : Form
        {   
            var toForm = (TTo)Activator.CreateInstance(typeof(TTo), args);

            toForm.StartPosition = FormStartPosition.Manual;
            toForm.Bounds = fromForm.Bounds;
            toForm.Size = new System.Drawing.Size(800, 500);
            toForm.FormBorderStyle = FormBorderStyle.FixedSingle;

            fromForm.Close();
            fromForm.Dispose();
            toForm.ShowDialog();
        }
    }
}
