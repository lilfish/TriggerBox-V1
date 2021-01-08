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
            test.stuff();

        }
    }
}
