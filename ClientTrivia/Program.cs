//#define TEST

using System;
using System.Collections.Generic;
using System.Drawing.Text;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using ClientTrivia.Forms;

namespace ClientTrivia
{

    internal static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

#if !TEST
            //Utils.player.Play();

            //if (!Communicator.GetInstance().checkForConnection())
            //{
            //    MessageBox.Show("Server is not connected!",
            //                    "Alert",
            //                    MessageBoxButtons.OK,
            //                    MessageBoxIcon.Warning);
            //    return;
            //}
#endif
            Utils.SwapForms<LogIn, LogIn>(new LogIn());
            Console.WriteLine("Great success");
        }
    }
}
