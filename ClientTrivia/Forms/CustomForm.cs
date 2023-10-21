using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClientTrivia
{
    public partial class CustomForm : Form
    {
        // *TODO*
        // Change to const later.
        public CustomForm()
        {
            InitializeComponent();
        }
        protected void CustomInit()
        {
            InitializeComponent();
            ApplyCustomFont();
        }
        protected void ApplyCustomFont()
        {
            for (int index = 0; index < Controls.Count; index++)
            {
                Controls[index].Font = new Font(Utils.pfc.Families[0], Controls[index].Font.Size);
                
                if (Controls[index] is Button button)
                    button.UseCompatibleTextRendering = true;

                //if (Controls[index] is DataGridView dataGrid)
                //{
                //    dataGrid.DefaultCellStyle.Font = new Font(Utils.pfc.Families[0], 15f, GraphicsUnit.Pixel);
                //    dataGrid.ColumnHeadersDefaultCellStyle.Font = new Font(Utils.pfc.Families[0], dataGrid.ColumnHeadersDefaultCellStyle.Font.Size);
                //}

                if (Controls[index] is Label label)
                {
                    label.UseCompatibleTextRendering = true;
                    label.Parent = BackGroundAnimation;
                    label.BackColor = System.Drawing.Color.Transparent;
                    label.ForeColor = System.Drawing.Color.DarkGray;
                    label.Font = new System.Drawing.Font(label.Font, System.Drawing.FontStyle.Bold);
                    index--;
                }
            }
        }
    }
}
