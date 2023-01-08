using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LoggerControllSoft
{
    public partial class Form3 : Form
    {
        private String serial_port;
        private SerialPort serialPort;
        const float MAX_RANGE_CURRENT = 0.888F;
        const float MAX_RANGE_VOLTAGE = 9.071F;

        public Form3(string serial_port_name)
        {
            serial_port = serial_port_name;
            RichTextBox.CheckForIllegalCrossThreadCalls = false;
            ProgressBar.CheckForIllegalCrossThreadCalls = false;

            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {
           
        }

        public void Thread_read()
        {
            Thread.Sleep(1000);
            serialPort.WriteLine("SYNC");
            int length = 0;
            var response = serialPort.ReadLine();
            if (response != null)
            {
                response = response.Replace("DATA+", "");
                length = int.Parse(response);
                MessageBox.Show(response);
            }

            ArrayList data = new ArrayList();
            for (int i = 0; i < length; i++)
            {
                var input = serialPort.ReadLine();
                var input_array = input.Split(',');
                var voltage_hex = input_array[0].Replace("0x", "");
                var current_hex = input_array[1].Replace("0x", "");
                var voltage = int.Parse(voltage_hex) * 4 * (MAX_RANGE_VOLTAGE / 1023.0);
                var current = int.Parse(current_hex) * 4 * (MAX_RANGE_CURRENT / 1023.0);
                data.Add(voltage.ToString() + "," + current.ToString());
                float division = (i / length);
                progressBar1.Value = (int)(division * 100);


            }
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.ShowDialog();
            File.WriteAllLines(saveFileDialog.FileName, data.Cast<string>());
            MessageBox.Show("Saved ...OK");
            if (checkBox1.Checked == true)
            {
                serialPort.Write("ERASE");
                Thread.Sleep(1000);
                serialPort.Close();
                MessageBox.Show("ERASE>..OK");
            }
          


        }
        private void button1_Click(object sender, EventArgs e)
        {
            Thread_read();
        }
    }
}
