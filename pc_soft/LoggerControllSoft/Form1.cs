using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System;
using System.IO.Ports;
using System.Threading;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Collections;
using System.IO;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;
using System.Reflection;
using System.Security.Policy;

namespace LoggerControllSoft
{
    public partial class Form1 : Form
    {
        private ArrayList data_array_list;
        private SerialPort serialPort;
        const float MAX_RANGE_CURRENT = 0.888F;
        const float MAX_RANGE_VOLTAGE = 9.071F;
        public Form1()
        {
            InitializeComponent();
            DataGridView.CheckForIllegalCrossThreadCalls = false;
            System.Windows.Forms.ComboBox.CheckForIllegalCrossThreadCalls = false;
            ribbonButton1.Click += button1_Click;
            ribbonButton2.Click += button1_Click;
            ribbonButton7.Click += button4_Click;
            ribbonButton8.Click += button6_Click;
            ribbonButton9.Click += button3_Click;
            ribbonLabel2.Text = "Version:" + System.Reflection.Assembly.GetEntryAssembly().GetName().Version.ToString();
            ribbonOrbMenuItem1.Click += about;
            ribbonOrbMenuItem2.Click += open_updates;
            ribbonOrbMenuItem3.Click += open_updates;
            ribbonOrbMenuItem4.Click += drivers_updates;
            serialPort = new SerialPort();
            this.FormClosing += new FormClosingEventHandler(Form1_FormClosing);





            var list_of_ports = SerialPort.GetPortNames();

            foreach (string port in list_of_ports)

            {
                var sample = new RibbonLabel();
                sample.Text = port;
                ribbonComboBox1.DropDownItems.Add(sample);
            }





        }
        

private void Form1_FormClosing(Object sender, FormClosingEventArgs e)
        {
            serialPort.Close();
            DialogResult d = MessageBox.Show("Confirm closing", "AppTitle", MessageBoxButtons.YesNo);
            if (d == DialogResult.No)
                e.Cancel = true;
            

        }
        public void open_updates(object sender, EventArgs e)
        {
            var url = "https://github.com/alex5250/console_panel_software";
            System.Diagnostics.Process.Start("explorer.exe", $"\"{url}\"");
        }
        public void drivers_updates(object sender, EventArgs e)
        {
            var url = "https://github.com/alex5250/console_panel_software/drivers";
            System.Diagnostics.Process.Start("explorer.exe", $"\"{url}\"");
        }
        public void read_data_logger()
        {
            data_array_list = new ArrayList();
            data_array_list.Add("Voltage /(V), Current /(A)");
            try
            {
                
                //richTextBox1.Visible = false;
                try
                {
                    if (ribbonComboBox1.SelectedItem != null)
                    {
                        var port = ribbonComboBox1.SelectedItem.Text;
                        serialPort.PortName = port;
                        serialPort.BaudRate = 115200;
                    }
                    else
                    {
                        MessageBox.Show("No port selected....");
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);    
                }


                richTextBox1.Text = "Voltage /(V), Current /(A)";





                serialPort.Open();


                while (true)

                {
                    var data = serialPort.ReadLine().Split(',');
                    if (data.Length > 0)
                    {
                        try
                        {

                            var data_value = data[0] + "," + data[1] + "\n";
                            richTextBox1.AppendText(data_value);
                            data_array_list.Add (data_value);








                        }
                        catch (Exception a)
                        {
                            Console.Write(a.Message);
                            Console.Write(a.StackTrace);

                        }

                    }

                }
            }
            catch (Exception a)
            {
                Console.Write(a.Message);

            }
        } 


            private void button1_Click(object sender, EventArgs e)
        {
            Thread thread = new Thread(read_data_logger);
            thread.Start();
        }

        private void about(object sender, EventArgs e)
        {
           var text= File.GetCreationTime(Assembly.GetExecutingAssembly().Location);
            var version="Version:" + System.Reflection.Assembly.GetEntryAssembly().GetName().Version.ToString();

            MessageBox.Show(text + "\n" + version);
        }

            private void button3_Click(object sender, EventArgs e)
        {
            try
            {


                if (ribbonComboBox1.SelectedItem != null)
                {
                    var port = ribbonComboBox1.SelectedItem.Text;
                    serialPort.PortName = port;
                    serialPort.BaudRate = 115200;
                    serialPort.Open();
                    Thread.Sleep(1000);
                    serialPort.Write("TIME\n");
                    serialPort.Write(ribbonTextBox1.TextBoxText);
                    serialPort.Close();
                }
                else
                {
                    MessageBox.Show("No port selected....");
                }


            }
            catch (Exception a)
            {
                MessageBox.Show(a.Message);

            }
        }

     
            private void Form1_Load(object sender, EventArgs e)
        {

        }
        public void Thread_read()
        {
            try
            {
                if (ribbonComboBox1.SelectedItem != null)
                {
                    var port = ribbonComboBox1.SelectedItem.Text;
                    serialPort.PortName = port;
                    serialPort.PortName = ribbonComboBox1.SelectedItem.Text;
                    serialPort.BaudRate = 115200;
                    serialPort.Open();
                    Thread.Sleep(1000);
                    richTextBox1.AppendText("SYNC package sent///");
                    serialPort.WriteLine("SYNC");
                    int length = 0;
                    var response = serialPort.ReadLine();
                    if (response != null)
                    {
                        response = response.Replace("DATA+", "");
                        length = int.Parse(response);
                        // MessageBox.Show(response);
                        richTextBox1.AppendText("Response got..." + response);
                    }

                    ArrayList data = new ArrayList();
                    data.Add("Voltage / V,Current /A");
                         for (int i = 0; i < length; i++)
                    {
                        var input = serialPort.ReadLine();
                        var input_array = input.Split(',');
                        var voltage_hex = input_array[0].Replace("0x", "");
                        var current_hex = input_array[1].Replace("0x", "");
                        var voltage = (int.Parse(voltage_hex)-1) * 4 * (MAX_RANGE_VOLTAGE / 1023.0);
                        var current = (int.Parse(current_hex)-1) * 4 * (MAX_RANGE_CURRENT / 1023.0);
                        data.Add(voltage.ToString() + "," + current.ToString());
                        float division = (i / length);
                        richTextBox1.AppendText("Binarry from eeprom" + input);
                


                    }
                 
                    SaveFileDialog saveFileDialog = new SaveFileDialog();
                    saveFileDialog.ShowDialog();
                    richTextBox1.AppendText("Save dialog");
                    File.WriteAllLines(saveFileDialog.FileName, data.Cast<string>());
                    // MessageBox.Show("Saved ...OK");
                    richTextBox1.AppendText("Saved ok");
                    if (ribbonCheckBox1.Checked == true)
                    {
                        serialPort.Write("ERASE");
                        Thread.Sleep(1000);
                        serialPort.Close();

                        richTextBox1.AppendText("ERASE>..OK");
                    }
                    MessageBox.Show("Job done");
                    richTextBox1.Text = "All tasks finnished okay";

                    serialPort.Close();
                }

                else
                {
                    MessageBox.Show("No port selected....");
                }
            }

            catch (Exception a)
            {
                MessageBox.Show(a.Message);

            }



        }
        private void button6_Click(object sender, EventArgs e)
        {
            Thread_read();
        }
        private void button4_Click(object sender, EventArgs e)
        {
            SaveFileDialog dialog = new SaveFileDialog();
            //saveFileDialogdialog.ShowHelp();
            dialog.ShowDialog(this);
            File.WriteAllLines(dialog.FileName, data_array_list.Cast<string>());
     
        }

    
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            Thread thread = new Thread(read_data_logger);
            thread.Start();
        }

        private void ribbon1_Click(object sender, EventArgs e)
        {

        }
    }
}
