using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TriggerBoxApplication
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void addBlockButton_Click(object sender, EventArgs e)
        {
            Console.WriteLine("HERE");
            Console.WriteLine(MotorAccelA.Text);
            MotorClass test = new MotorClass();
            test.setStart(TimeSetter.Value);
            test.stuff();

        }

        private void RelayDurationA_TextChanged(object sender, EventArgs e)
        {

        }

        private void RelayDurationB_TextChanged(object sender, EventArgs e)
        {

        }

        private void RelayDurationC_TextChanged(object sender, EventArgs e)
        {

        }

        private void RelayDurationD_TextChanged(object sender, EventArgs e)
        {

        }

        private void RelayDurationE_TextChanged(object sender, EventArgs e)
        {

        }

        private void RelayDurationF_TextChanged(object sender, EventArgs e)
        {

        }

        private void label24_Click(object sender, EventArgs e)
        {

        }

        private void groupBox4_Enter(object sender, EventArgs e)
        {

        }
    }
}
