
namespace TriggerBoxApplication
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label27 = new System.Windows.Forms.Label();
            this.MotorGotoA = new System.Windows.Forms.TextBox();
            this.MotorAccelA = new System.Windows.Forms.TextBox();
            this.label21 = new System.Windows.Forms.Label();
            this.label20 = new System.Windows.Forms.Label();
            this.MotorDurationA = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label22 = new System.Windows.Forms.Label();
            this.label23 = new System.Windows.Forms.Label();
            this.PWMvalA = new System.Windows.Forms.TextBox();
            this.PWMDurationA = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label25 = new System.Windows.Forms.Label();
            this.RelayOptionBoxA = new System.Windows.Forms.ComboBox();
            this.addBlockButton = new System.Windows.Forms.Button();
            this.label19 = new System.Windows.Forms.Label();
            this.uploadButton = new System.Windows.Forms.Button();
            this.label26 = new System.Windows.Forms.Label();
            this.statusLabel = new System.Windows.Forms.Label();
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.TimeSetter = new System.Windows.Forms.DateTimePicker();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.label28 = new System.Windows.Forms.Label();
            this.ServoPosA = new System.Windows.Forms.TextBox();
            this.label29 = new System.Windows.Forms.Label();
            this.label30 = new System.Windows.Forms.Label();
            this.ServoDurA = new System.Windows.Forms.TextBox();
            this.ServoEasA = new System.Windows.Forms.ComboBox();
            this.ClearMotors = new System.Windows.Forms.Button();
            this.ServosClear = new System.Windows.Forms.Button();
            this.PWMClear = new System.Windows.Forms.Button();
            this.RelaysClear = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.ClearMotors);
            this.groupBox1.Controls.Add(this.label27);
            this.groupBox1.Controls.Add(this.MotorGotoA);
            this.groupBox1.Controls.Add(this.MotorAccelA);
            this.groupBox1.Controls.Add(this.label21);
            this.groupBox1.Controls.Add(this.label20);
            this.groupBox1.Controls.Add(this.MotorDurationA);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(264, 248);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Motors";
            // 
            // label27
            // 
            this.label27.AutoSize = true;
            this.label27.Location = new System.Drawing.Point(175, 30);
            this.label27.Name = "label27";
            this.label27.Size = new System.Drawing.Size(34, 13);
            this.label27.TabIndex = 27;
            this.label27.Text = "GoTo";
            // 
            // MotorGotoA
            // 
            this.MotorGotoA.Location = new System.Drawing.Point(178, 46);
            this.MotorGotoA.Name = "MotorGotoA";
            this.MotorGotoA.Size = new System.Drawing.Size(70, 20);
            this.MotorGotoA.TabIndex = 26;
            // 
            // MotorAccelA
            // 
            this.MotorAccelA.Location = new System.Drawing.Point(26, 46);
            this.MotorAccelA.Name = "MotorAccelA";
            this.MotorAccelA.Size = new System.Drawing.Size(70, 20);
            this.MotorAccelA.TabIndex = 20;
            // 
            // label21
            // 
            this.label21.AutoSize = true;
            this.label21.Location = new System.Drawing.Point(99, 30);
            this.label21.Name = "label21";
            this.label21.Size = new System.Drawing.Size(41, 13);
            this.label21.TabIndex = 19;
            this.label21.Text = "Duratie";
            // 
            // label20
            // 
            this.label20.AutoSize = true;
            this.label20.Location = new System.Drawing.Point(23, 30);
            this.label20.Name = "label20";
            this.label20.Size = new System.Drawing.Size(62, 13);
            this.label20.TabIndex = 18;
            this.label20.Text = "Accelleratie";
            // 
            // MotorDurationA
            // 
            this.MotorDurationA.Location = new System.Drawing.Point(102, 46);
            this.MotorDurationA.Name = "MotorDurationA";
            this.MotorDurationA.Size = new System.Drawing.Size(70, 20);
            this.MotorDurationA.TabIndex = 12;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.PWMClear);
            this.groupBox2.Controls.Add(this.label22);
            this.groupBox2.Controls.Add(this.label23);
            this.groupBox2.Controls.Add(this.PWMvalA);
            this.groupBox2.Controls.Add(this.PWMDurationA);
            this.groupBox2.Location = new System.Drawing.Point(552, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(173, 248);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "PWM";
            // 
            // label22
            // 
            this.label22.AutoSize = true;
            this.label22.Location = new System.Drawing.Point(92, 30);
            this.label22.Name = "label22";
            this.label22.Size = new System.Drawing.Size(41, 13);
            this.label22.TabIndex = 21;
            this.label22.Text = "Duratie";
            // 
            // label23
            // 
            this.label23.AutoSize = true;
            this.label23.Location = new System.Drawing.Point(21, 29);
            this.label23.Name = "label23";
            this.label23.Size = new System.Drawing.Size(63, 13);
            this.label23.TabIndex = 20;
            this.label23.Text = "Sterkte in %";
            // 
            // PWMvalA
            // 
            this.PWMvalA.Location = new System.Drawing.Point(24, 46);
            this.PWMvalA.Name = "PWMvalA";
            this.PWMvalA.Size = new System.Drawing.Size(65, 20);
            this.PWMvalA.TabIndex = 33;
            // 
            // PWMDurationA
            // 
            this.PWMDurationA.Location = new System.Drawing.Point(95, 46);
            this.PWMDurationA.Name = "PWMDurationA";
            this.PWMDurationA.Size = new System.Drawing.Size(65, 20);
            this.PWMDurationA.TabIndex = 18;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.RelaysClear);
            this.groupBox3.Controls.Add(this.label25);
            this.groupBox3.Controls.Add(this.RelayOptionBoxA);
            this.groupBox3.Location = new System.Drawing.Point(731, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(114, 248);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Relays";
            // 
            // label25
            // 
            this.label25.AutoSize = true;
            this.label25.Location = new System.Drawing.Point(21, 29);
            this.label25.Name = "label25";
            this.label25.Size = new System.Drawing.Size(32, 13);
            this.label25.TabIndex = 24;
            this.label25.Text = "Optie";
            // 
            // RelayOptionBoxA
            // 
            this.RelayOptionBoxA.FormattingEnabled = true;
            this.RelayOptionBoxA.Location = new System.Drawing.Point(24, 45);
            this.RelayOptionBoxA.Name = "RelayOptionBoxA";
            this.RelayOptionBoxA.Size = new System.Drawing.Size(77, 21);
            this.RelayOptionBoxA.TabIndex = 25;
            // 
            // addBlockButton
            // 
            this.addBlockButton.Location = new System.Drawing.Point(217, 286);
            this.addBlockButton.Name = "addBlockButton";
            this.addBlockButton.Size = new System.Drawing.Size(75, 23);
            this.addBlockButton.TabIndex = 3;
            this.addBlockButton.Text = "Toevoegen";
            this.addBlockButton.UseVisualStyleBackColor = true;
            this.addBlockButton.Click += new System.EventHandler(this.addBlockButton_Click);
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(9, 273);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(83, 13);
            this.label19.TabIndex = 5;
            this.label19.Text = "Start tijd (m:s:ss)";
            // 
            // uploadButton
            // 
            this.uploadButton.Location = new System.Drawing.Point(765, 286);
            this.uploadButton.Name = "uploadButton";
            this.uploadButton.Size = new System.Drawing.Size(75, 23);
            this.uploadButton.TabIndex = 6;
            this.uploadButton.Text = "Uploaden";
            this.uploadButton.UseVisualStyleBackColor = true;
            // 
            // label26
            // 
            this.label26.AutoSize = true;
            this.label26.Location = new System.Drawing.Point(6, 488);
            this.label26.Name = "label26";
            this.label26.Size = new System.Drawing.Size(40, 13);
            this.label26.TabIndex = 7;
            this.label26.Text = "Status:";
            // 
            // statusLabel
            // 
            this.statusLabel.AutoSize = true;
            this.statusLabel.Location = new System.Drawing.Point(52, 488);
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size(16, 13);
            this.statusLabel.TabIndex = 8;
            this.statusLabel.Text = "---";
            // 
            // progressBar
            // 
            this.progressBar.Location = new System.Drawing.Point(742, 475);
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(100, 23);
            this.progressBar.TabIndex = 9;
            // 
            // TimeSetter
            // 
            this.TimeSetter.CustomFormat = "HH:MM:SS";
            this.TimeSetter.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.TimeSetter.Location = new System.Drawing.Point(11, 289);
            this.TimeSetter.Name = "TimeSetter";
            this.TimeSetter.Size = new System.Drawing.Size(200, 20);
            this.TimeSetter.TabIndex = 0;
            this.TimeSetter.Value = new System.DateTime(2020, 12, 28, 0, 0, 0, 0);
            // 
            // button1
            // 
            this.button1.Enabled = false;
            this.button1.Location = new System.Drawing.Point(684, 286);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 11;
            this.button1.Text = "Updaten";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.ServosClear);
            this.groupBox4.Controls.Add(this.ServoEasA);
            this.groupBox4.Controls.Add(this.label28);
            this.groupBox4.Controls.Add(this.ServoPosA);
            this.groupBox4.Controls.Add(this.label29);
            this.groupBox4.Controls.Add(this.label30);
            this.groupBox4.Controls.Add(this.ServoDurA);
            this.groupBox4.Location = new System.Drawing.Point(282, 12);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(264, 248);
            this.groupBox4.TabIndex = 33;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Servos";
            this.groupBox4.Enter += new System.EventHandler(this.groupBox4_Enter);
            // 
            // label28
            // 
            this.label28.AutoSize = true;
            this.label28.Location = new System.Drawing.Point(175, 30);
            this.label28.Name = "label28";
            this.label28.Size = new System.Drawing.Size(39, 13);
            this.label28.TabIndex = 27;
            this.label28.Text = "Easing";
            // 
            // ServoPosA
            // 
            this.ServoPosA.Location = new System.Drawing.Point(26, 46);
            this.ServoPosA.Name = "ServoPosA";
            this.ServoPosA.Size = new System.Drawing.Size(70, 20);
            this.ServoPosA.TabIndex = 20;
            // 
            // label29
            // 
            this.label29.AutoSize = true;
            this.label29.Location = new System.Drawing.Point(99, 30);
            this.label29.Name = "label29";
            this.label29.Size = new System.Drawing.Size(41, 13);
            this.label29.TabIndex = 19;
            this.label29.Text = "Duratie";
            // 
            // label30
            // 
            this.label30.AutoSize = true;
            this.label30.Location = new System.Drawing.Point(23, 30);
            this.label30.Name = "label30";
            this.label30.Size = new System.Drawing.Size(38, 13);
            this.label30.TabIndex = 18;
            this.label30.Text = "Positie";
            // 
            // ServoDurA
            // 
            this.ServoDurA.Location = new System.Drawing.Point(102, 46);
            this.ServoDurA.Name = "ServoDurA";
            this.ServoDurA.Size = new System.Drawing.Size(70, 20);
            this.ServoDurA.TabIndex = 12;
            // 
            // ServoEasA
            // 
            this.ServoEasA.FormattingEnabled = true;
            this.ServoEasA.Location = new System.Drawing.Point(178, 46);
            this.ServoEasA.Name = "ServoEasA";
            this.ServoEasA.Size = new System.Drawing.Size(77, 21);
            this.ServoEasA.TabIndex = 36;
            // 
            // ClearMotors
            // 
            this.ClearMotors.Location = new System.Drawing.Point(183, 219);
            this.ClearMotors.Name = "ClearMotors";
            this.ClearMotors.Size = new System.Drawing.Size(75, 23);
            this.ClearMotors.TabIndex = 34;
            this.ClearMotors.Text = "Clear";
            this.ClearMotors.UseVisualStyleBackColor = true;
            // 
            // ServosClear
            // 
            this.ServosClear.Location = new System.Drawing.Point(183, 219);
            this.ServosClear.Name = "ServosClear";
            this.ServosClear.Size = new System.Drawing.Size(75, 23);
            this.ServosClear.TabIndex = 35;
            this.ServosClear.Text = "Clear";
            this.ServosClear.UseVisualStyleBackColor = true;
            // 
            // PWMClear
            // 
            this.PWMClear.Location = new System.Drawing.Point(92, 219);
            this.PWMClear.Name = "PWMClear";
            this.PWMClear.Size = new System.Drawing.Size(75, 23);
            this.PWMClear.TabIndex = 42;
            this.PWMClear.Text = "Clear";
            this.PWMClear.UseVisualStyleBackColor = true;
            // 
            // RelaysClear
            // 
            this.RelaysClear.Location = new System.Drawing.Point(33, 219);
            this.RelaysClear.Name = "RelaysClear";
            this.RelaysClear.Size = new System.Drawing.Size(75, 23);
            this.RelaysClear.TabIndex = 43;
            this.RelaysClear.Text = "Clear";
            this.RelaysClear.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(858, 505);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.TimeSetter);
            this.Controls.Add(this.progressBar);
            this.Controls.Add(this.statusLabel);
            this.Controls.Add(this.label26);
            this.Controls.Add(this.uploadButton);
            this.Controls.Add(this.label19);
            this.Controls.Add(this.addBlockButton);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "TriggerBox Applicatie V1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label21;
        private System.Windows.Forms.Label label20;
        private System.Windows.Forms.TextBox MotorDurationA;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label23;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label25;
        private System.Windows.Forms.ComboBox RelayOptionBoxA;
        private System.Windows.Forms.Button addBlockButton;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.Button uploadButton;
        private System.Windows.Forms.Label label26;
        private System.Windows.Forms.Label statusLabel;
        private System.Windows.Forms.ProgressBar progressBar;
        private System.Windows.Forms.Label label27;
        private System.Windows.Forms.TextBox MotorGotoA;
        private System.Windows.Forms.TextBox MotorAccelA;
        private System.Windows.Forms.TextBox PWMvalA;
        private System.Windows.Forms.DateTimePicker TimeSetter;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label22;
        private System.Windows.Forms.TextBox PWMDurationA;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Label label28;
        private System.Windows.Forms.TextBox ServoPosA;
        private System.Windows.Forms.Label label29;
        private System.Windows.Forms.Label label30;
        private System.Windows.Forms.TextBox ServoDurA;
        private System.Windows.Forms.ComboBox ServoEasA;
        private System.Windows.Forms.Button ClearMotors;
        private System.Windows.Forms.Button PWMClear;
        private System.Windows.Forms.Button RelaysClear;
        private System.Windows.Forms.Button ServosClear;
    }
}

