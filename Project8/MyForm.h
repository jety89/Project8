#pragma once

using namespace System::IO;
namespace Arduino_Read {

	using namespace System;
	using namespace System::Globalization;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::IO::Ports;
	using namespace System::Text::RegularExpressions;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// Ñâîäêà äëÿ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			findPorts();
			openIni();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		~Form1()
		{
			if (components)
			{
				delete components;
			}
			serialPort1->Close();

			timer1->Stop();
		}
	private: System::IO::Ports::SerialPort^ serialPort1;
	protected:
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;

	private:
		/// <summary>
		/// Required designer variable.
		String^ mStr = "1";
		String^ prvt;
		int COM;
		int Speed;
		int Aver;
		int T_min;
		int T_max;
		int T_1;
		int Time_1;
		int timerA = 0;
		int timerB = 0;
		int pos;
		
		Char inc;
		int val;
		int millis, temp, C, D;
		array<Char>^ arr;







	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;


	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ sendDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ instuctionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::Button^ button7;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label10;

	private: System::Windows::Forms::TextBox^ textBox9;
		   /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			   System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			   System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			   this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			   this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			   this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->label12 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->label13 = (gcnew System::Windows::Forms::Label());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->sendDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->instuctionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label14 = (gcnew System::Windows::Forms::Label());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			   this->menuStrip1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label1->Location = System::Drawing::Point(604, 45);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(63, 28);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"label1";
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 500;
			   this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(599, 97);
			   this->textBox2->Margin = System::Windows::Forms::Padding(2);
			   this->textBox2->Multiline = true;
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(113, 104);
			   this->textBox2->TabIndex = 3;
			   // 
			   // button2
			   // 
			   this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button2->Location = System::Drawing::Point(599, 228);
			   this->button2->Margin = System::Windows::Forms::Padding(2);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(82, 34);
			   this->button2->TabIndex = 4;
			   this->button2->Text = L"Зберегти";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			   // 
			   // richTextBox1
			   // 
			   this->richTextBox1->Location = System::Drawing::Point(960, 68);
			   this->richTextBox1->Margin = System::Windows::Forms::Padding(2);
			   this->richTextBox1->Name = L"richTextBox1";
			   this->richTextBox1->Size = System::Drawing::Size(132, 263);
			   this->richTextBox1->TabIndex = 5;
			   this->richTextBox1->Text = L"";
			   // 
			   // button3
			   // 
			   this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button3->Location = System::Drawing::Point(40, 80);
			   this->button3->Margin = System::Windows::Forms::Padding(2);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(124, 36);
			   this->button3->TabIndex = 6;
			   this->button3->Text = L"Підключити";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Location = System::Drawing::Point(51, 54);
			   this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(108, 21);
			   this->comboBox1->TabIndex = 7;
			   this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label3->Location = System::Drawing::Point(15, 38);
			   this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(72, 21);
			   this->label3->TabIndex = 9;
			   this->label3->Text = L"Speed =";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label4->Location = System::Drawing::Point(25, 70);
			   this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(59, 21);
			   this->label4->TabIndex = 10;
			   this->label4->Text = L"Aver =";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label5->Location = System::Drawing::Point(15, 100);
			   this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(68, 21);
			   this->label5->TabIndex = 11;
			   this->label5->Text = L"T_min =";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label6->Location = System::Drawing::Point(12, 127);
			   this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(71, 21);
			   this->label6->TabIndex = 12;
			   this->label6->Text = L"T_max =";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label7->Location = System::Drawing::Point(35, 156);
			   this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(47, 21);
			   this->label7->TabIndex = 13;
			   this->label7->Text = L"T_1 =";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label8->Location = System::Drawing::Point(7, 184);
			   this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(74, 21);
			   this->label8->TabIndex = 14;
			   this->label8->Text = L"Time_1 =";
			   // 
			   // textBox4
			   // 
			   this->textBox4->Location = System::Drawing::Point(94, 42);
			   this->textBox4->Margin = System::Windows::Forms::Padding(2);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(76, 20);
			   this->textBox4->TabIndex = 16;
			   // 
			   // textBox5
			   // 
			   this->textBox5->Location = System::Drawing::Point(94, 74);
			   this->textBox5->Margin = System::Windows::Forms::Padding(2);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->Size = System::Drawing::Size(76, 20);
			   this->textBox5->TabIndex = 17;
			   // 
			   // textBox6
			   // 
			   this->textBox6->Location = System::Drawing::Point(94, 104);
			   this->textBox6->Margin = System::Windows::Forms::Padding(2);
			   this->textBox6->Name = L"textBox6";
			   this->textBox6->Size = System::Drawing::Size(76, 20);
			   this->textBox6->TabIndex = 18;
			   // 
			   // textBox7
			   // 
			   this->textBox7->Location = System::Drawing::Point(94, 132);
			   this->textBox7->Margin = System::Windows::Forms::Padding(2);
			   this->textBox7->Name = L"textBox7";
			   this->textBox7->Size = System::Drawing::Size(76, 20);
			   this->textBox7->TabIndex = 19;
			   // 
			   // textBox8
			   // 
			   this->textBox8->Location = System::Drawing::Point(94, 161);
			   this->textBox8->Margin = System::Windows::Forms::Padding(2);
			   this->textBox8->Name = L"textBox8";
			   this->textBox8->Size = System::Drawing::Size(76, 20);
			   this->textBox8->TabIndex = 20;
			   // 
			   // textBox9
			   // 
			   this->textBox9->Location = System::Drawing::Point(94, 188);
			   this->textBox9->Margin = System::Windows::Forms::Padding(2);
			   this->textBox9->Name = L"textBox9";
			   this->textBox9->Size = System::Drawing::Size(76, 20);
			   this->textBox9->TabIndex = 21;
			   // 
			   // chart1
			   // 
			   chartArea2->Name = L"ChartArea1";
			   this->chart1->ChartAreas->Add(chartArea2);
			   legend2->Name = L"Legend1";
			   this->chart1->Legends->Add(legend2);
			   this->chart1->Location = System::Drawing::Point(23, 310);
			   this->chart1->Margin = System::Windows::Forms::Padding(2);
			   this->chart1->Name = L"chart1";
			   series2->ChartArea = L"ChartArea1";
			   series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			   series2->Legend = L"Legend1";
			   series2->Name = L"Series1";
			   this->chart1->Series->Add(series2);
			   this->chart1->Size = System::Drawing::Size(924, 316);
			   this->chart1->TabIndex = 22;
			   this->chart1->Text = L"chart1";
			   // 
			   // button5
			   // 
			   this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
			   this->button5->Location = System::Drawing::Point(40, 121);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(124, 46);
			   this->button5->TabIndex = 25;
			   this->button5->Text = L"Надіслати\r\nпараметри";
			   this->button5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label2->Location = System::Drawing::Point(12, 31);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(158, 21);
			   this->label2->TabIndex = 26;
			   this->label2->Text = L"Виберіть COM порт";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label9->Location = System::Drawing::Point(12, 87);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(23, 21);
			   this->label9->TabIndex = 27;
			   this->label9->Text = L"2.";
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label11->Location = System::Drawing::Point(12, 131);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(23, 21);
			   this->label11->TabIndex = 29;
			   this->label11->Text = L"3.";
			   // 
			   // label12
			   // 
			   this->label12->AutoSize = true;
			   this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold));
			   this->label12->Location = System::Drawing::Point(12, 174);
			   this->label12->Name = L"label12";
			   this->label12->Size = System::Drawing::Size(144, 40);
			   this->label12->TabIndex = 30;
			   this->label12->Text = L"4. Зачекайте поки \r\nустановка охолоне";
			   this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button1->Location = System::Drawing::Point(51, 220);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(99, 42);
			   this->button1->TabIndex = 31;
			   this->button1->Text = L"Старт";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			   // 
			   // label13
			   // 
			   this->label13->Location = System::Drawing::Point(0, 0);
			   this->label13->Name = L"label13";
			   this->label13->Size = System::Drawing::Size(100, 23);
			   this->label13->TabIndex = 39;
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				   this->fileToolStripMenuItem,
					   this->editToolStripMenuItem, this->toolsToolStripMenuItem, this->optionsToolStripMenuItem, this->helpToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(963, 24);
			   this->menuStrip1->TabIndex = 33;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->openToolStripMenuItem,
					   this->saveToolStripMenuItem, this->exitToolStripMenuItem
			   });
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // openToolStripMenuItem
			   // 
			   this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			   this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			   this->openToolStripMenuItem->Text = L"Open";
			   // 
			   // saveToolStripMenuItem
			   // 
			   this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			   this->saveToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			   this->saveToolStripMenuItem->Text = L"Save";
			   // 
			   // exitToolStripMenuItem
			   // 
			   this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			   this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			   this->exitToolStripMenuItem->Text = L"Exit";
			   // 
			   // editToolStripMenuItem
			   // 
			   this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			   this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			   this->editToolStripMenuItem->Text = L"Edit";
			   // 
			   // toolsToolStripMenuItem
			   // 
			   this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->sendDataToolStripMenuItem });
			   this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			   this->toolsToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			   this->toolsToolStripMenuItem->Text = L"Tools";
			   // 
			   // sendDataToolStripMenuItem
			   // 
			   this->sendDataToolStripMenuItem->Name = L"sendDataToolStripMenuItem";
			   this->sendDataToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			   this->sendDataToolStripMenuItem->Text = L"Send data";
			   // 
			   // optionsToolStripMenuItem
			   // 
			   this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			   this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			   this->optionsToolStripMenuItem->Text = L"Options";
			   // 
			   // helpToolStripMenuItem
			   // 
			   this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->instuctionsToolStripMenuItem,
					   this->aboutToolStripMenuItem
			   });
			   this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			   this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			   this->helpToolStripMenuItem->Text = L"Help";
			   // 
			   // instuctionsToolStripMenuItem
			   // 
			   this->instuctionsToolStripMenuItem->Name = L"instuctionsToolStripMenuItem";
			   this->instuctionsToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			   this->instuctionsToolStripMenuItem->Text = L"Instuctions";
			   this->instuctionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::instuctionsToolStripMenuItem_Click);
			   // 
			   // aboutToolStripMenuItem
			   // 
			   this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			   this->aboutToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			   this->aboutToolStripMenuItem->Text = L"About";
			   this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			   // 
			   // button4
			   // 
			   this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button4->Location = System::Drawing::Point(185, 153);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(147, 37);
			   this->button4->TabIndex = 34;
			   this->button4->Text = L"Зберегти";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			   // 
			   // button6
			   // 
			   this->button6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button6->Location = System::Drawing::Point(185, 41);
			   this->button6->Margin = System::Windows::Forms::Padding(2);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(147, 37);
			   this->button6->TabIndex = 35;
			   this->button6->Text = L"За замовчуванням";
			   this->button6->UseVisualStyleBackColor = true;
			   this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			   // 
			   // button7
			   // 
			   this->button7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->button7->Location = System::Drawing::Point(185, 97);
			   this->button7->Margin = System::Windows::Forms::Padding(2);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(147, 37);
			   this->button7->TabIndex = 36;
			   this->button7->Text = L"Загрузити";
			   this->button7->UseVisualStyleBackColor = true;
			   this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::SystemColors::Control;
			   this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			   this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->panel1->Controls->Add(this->label14);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->button7);
			   this->panel1->Controls->Add(this->label4);
			   this->panel1->Controls->Add(this->button6);
			   this->panel1->Controls->Add(this->textBox4);
			   this->panel1->Controls->Add(this->button4);
			   this->panel1->Controls->Add(this->label5);
			   this->panel1->Controls->Add(this->label6);
			   this->panel1->Controls->Add(this->label7);
			   this->panel1->Controls->Add(this->label8);
			   this->panel1->Controls->Add(this->textBox5);
			   this->panel1->Controls->Add(this->textBox6);
			   this->panel1->Controls->Add(this->textBox7);
			   this->panel1->Controls->Add(this->textBox8);
			   this->panel1->Controls->Add(this->textBox9);
			   this->panel1->Location = System::Drawing::Point(227, 25);
			   this->panel1->Margin = System::Windows::Forms::Padding(2);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(343, 224);
			   this->panel1->TabIndex = 37;
			   // 
			   // label14
			   // 
			   this->label14->AutoSize = true;
			   this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label14->Location = System::Drawing::Point(2, 0);
			   this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label14->Name = L"label14";
			   this->label14->Size = System::Drawing::Size(101, 25);
			   this->label14->TabIndex = 37;
			   this->label14->Text = L"Параметри:";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold));
			   this->label10->Location = System::Drawing::Point(19, 279);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(128, 20);
			   this->label10->TabIndex = 38;
			   this->label10->Text = L"• RESET на ардуіно";
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(963, 645);
			   this->Controls->Add(this->label10);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->label13);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->label12);
			   this->Controls->Add(this->label11);
			   this->Controls->Add(this->label9);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->button5);
			   this->Controls->Add(this->chart1);
			   this->Controls->Add(this->comboBox1);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->richTextBox1);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"Form1";
			   this->Text = L"TL_RISE";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: void findPorts(void)
	{
		array<Object^>^ objectArray = SerialPort::GetPortNames();

		this->comboBox1->Items->AddRange(objectArray);
	}

	
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		//serialPort1->Open();
		//timer1->Start();
	}
	
	private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {

		val = 0;
		mStr = serialPort1->ReadLine();
		//mStr = serialPort1->ReadExisting();
		timerA = timerA + 1;
		//test correct parsing
	    //Console::WriteLine("AA");
	    //Console::WriteLine(mStr);
		//Console::WriteLine(mStr->Length);
		//Console::WriteLine("/AA");

		arr = mStr->ToCharArray(0, (mStr->Length - 1) );
		IEnumerator^ myEnum = arr->GetEnumerator();

		//Console::WriteLine("BBB");
		while (myEnum->MoveNext())
			{
				inc = safe_cast<Char>(myEnum->Current);
				//test correct parsing
				//Console::Write(inc);
				if (inc >= '0' && inc <= '9') {
					val = 10 * val + (inc - '0');
					
				}
				else {
					//Console::WriteLine();
					//Console::WriteLine(" val {0} inc {1} ", val, inc);
					val = 0;
					switch (inc) {

					case 'A':
						millis = val;
						Console::WriteLine("millis={0}", millis);
						break;

					case 'B':
						temp = val;
						Console::WriteLine("temp={0}", temp);
						break;

					case 'C':
						C = val;
						Console::WriteLine("C={0}", C);
						break;

					case 'D':
						D = val;
						Console::WriteLine("D={0}", D);
						debInf(C, D);
						//	C = 0;

						break;
					default:
						Console::WriteLine("Port buffer read error, inc ={0}", inc);
						break;

					}
				}
		}
		//Console::WriteLine("/BBB");

	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = mStr;
		textBox2->Text = mStr;
		// timer1->Interval = 1000;
		if (timerB != timerA) {
			prvt = prvt + mStr;
			richTextBox1->Text = prvt;
		}
		timerB = timerA;

		richTextBox1->Select(richTextBox1->Text->Length, 0);
		richTextBox1->ScrollToCaret();
		chart1->Series[0]->Points->AddY(mStr);

	}

		   //Save File
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
				
		saveFileDialog1->Filter = "Files|*.txt";

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			richTextBox1->SaveFile(saveFileDialog1->FileName);
		}


		
	}
		   //Connect Serial
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort1->IsOpen) {
		}
		else
		{
			serialPort1->PortName = comboBox1->Text;
			this->serialPort1->Open();
			timer1->Start();
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::serialPort1_DataReceived);
		}

	}


	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

		   //Debug info
	private: void debInf(int C, int D) {
	
		switch (D) {
			
		case '1':
			Console::WriteLine("D01 Speed = {0}", C);
			break;
		case '2':
			Console::WriteLine("D02 Aver = {0}", C);
			break;

		case '3':
			Console::WriteLine("D03 T_min = {0}", C);
			break;

		case '4':
			Console::WriteLine("D04 T_max = {0}", C);
			break;

		case '5':
			Console::WriteLine("D05 T1 = {0}", C);
			break;

		case '6':
			Console::WriteLine("D06 Time1_b = {0}", C);
			break;

		case '7':
			Console::WriteLine("D07 Echo");
			break;

		case '8':
			Console::WriteLine("D08 Arduino ON}");
			break;

		case '9':
			Console::WriteLine("D09 device too hot t = {0}", C);
			break;

		case '10':
			Console::WriteLine("D10 Start time = {0}", C);
			break;

		case '11':
			Console::WriteLine("D11 Heater ON");
			break;

		case '12':
			Console::WriteLine("D12 Heater OFF");
			break;

		case '13':
			Console::WriteLine("D13 timer ON time = {0}", C);
			break;

		case '14':
			Console::WriteLine("D14 timer OFF");
			break;

		case '15':
			Console::WriteLine("D15 debug");
			break;

		default:
			break;
		}
	}

	     //Open INI file
	private: void openIni(void) {
		String^ strfilename = "RUN_TL.INI";
		String^ Readfile = File::ReadAllText(strfilename);
		String^ pattern = "(\\w+)[=](\\d+)";

		Regex^ r = gcnew Regex(pattern, RegexOptions::IgnoreCase);
		Match^ m = r->Match(Readfile);

		int matchCount = 0;
		Int32 param[7];
		while (m->Success, matchCount < 6)
		{
			//Console::WriteLine("Match{0}", matchCount);
			int i = 2; // Regex 2 ãðóïà
			int j = 1;
			Group^ g = m->Groups[i];
			Group^ h = m->Groups[j];
			//Console::WriteLine("Group{0}='{1}'", i, g);
			matchCount++;
			param[matchCount] = Convert::ToInt32(g->Value);
			//Console::WriteLine("Param{0}='{1}', matchCount = {2}", i, param[matchCount], matchCount);
			//"COM", "Speed", "Aver", "T_min", "T_max", "T_1", "Time_1"
			if (h->Value == "Speed") { textBox4->Text = param[matchCount].ToString(); };
			if (h->Value == "Aver") { textBox5->Text = param[matchCount].ToString(); };
			if (h->Value == "T_min") { textBox6->Text = param[matchCount].ToString(); };
			if (h->Value == "T_max") { textBox7->Text = param[matchCount].ToString(); };
			if (h->Value == "T_1") { textBox8->Text = param[matchCount].ToString(); };
			if (h->Value == "Time_1") { textBox9->Text = param[matchCount].ToString(); };
			m = m->NextMatch();

		}
			}

		   //Load Default Values
		   private: void defaultIni(void) {
			   textBox4->Text = (16).ToString();
			   textBox5->Text = (8).ToString();
			   textBox6->Text = (30).ToString();
			   textBox7->Text = (300).ToString();
			   textBox8->Text = (270).ToString();
			   textBox9->Text = (50).ToString();
		   }


           //Send Parameters to arduino
	private:void SendParam(void) {
		String^ a = textBox4->Text;
		String^ b = textBox5->Text;
		String^ c = textBox6->Text;
		String^ d = textBox7->Text;
		String^ e = textBox8->Text;
		String^ f = textBox9->Text;

		// test string read
		Console::WriteLine("{0}A{1}B{2}C{3}D{4}E{5}F", a, b, c, d, e, f);

		serialPort1->WriteLine(String::Format("{0}A{1}B{2}C{3}D{4}E{5}F", a, b, c, d, e, f));
	}


	 private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ el) {
		 SendParam();
		
	 }
			//Start button
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	//serialPort1->WriteLine("Reset");
	//Thread::Sleep(500);
	//SendParam();
	//Thread::Sleep(500);
	serialPort1->WriteLine("Start");
	
	//SendParam();
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(this, "Run TL version 0.0.1 \n Peter Derecskei, Petro Yavorstyi \n Email: derecskei89@gmail.com, petro0798@gmail.com", "About Run TL", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void instuctionsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(this, "Êðîê 1:... ", "Instructions", MessageBoxButtons::OK, MessageBoxIcon::Question);

}

	   //Save button
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ el) {

	String^ a = textBox4->Text;
	String^ b = textBox5->Text;
	String^ c = textBox6->Text;
	String^ d = textBox7->Text;
	String^ e = textBox8->Text;
	String^ f = textBox9->Text;

	String^ strfilename = "RUN_TL.INI";
	String^ Readfile = File::ReadAllText(strfilename);
	//String^ Readfile = Rf;
	String^ Writefile;
	String^ pattern = "(\\w+)[=](\\d+)";

	// test 1
	Console::WriteLine(Readfile);

	Regex^ r = gcnew Regex(pattern, RegexOptions::IgnoreCase);
	Match^ m = r->Match(Readfile);

	int matchCount = 0;
	int i = 2; // Regex 2 ãðóïà
	int j = 1;
	int diff = 0;
	int index;
	Group^ g = m->Groups[i];
	Group^ h = m->Groups[j];
	while (m->Success, matchCount < 6)
	{
		 g = m->Groups[i];
		 h = m->Groups[j];
		//Console::WriteLine("Group{0}='{1}'", i, g);
		matchCount++;
		
		if (h->Value == "Speed") {
			// test 2
			index = g->Index + diff;
			diff = diff + a->Length - g->Length;
			Console::WriteLine(" {0}, {1}, diff = {2} ", g->Index, g->Length, diff);
			Writefile = Readfile->Remove(index, g->Length);
			Readfile = Writefile->Insert(index, a);
			

			//test 3
			//Console::WriteLine(Writefile);
				
		};

		if (h->Value == "Aver") { 
			index = g->Index + diff;
			diff = diff + b->Length - g->Length;
			Console::WriteLine(" {0}, {1}, diff = {2} ", g->Index, g->Length, diff);
			Writefile = Readfile->Remove(index, g->Length);
			Readfile = Writefile->Insert(index, b);
			
		};
		if (h->Value == "T_min") {
			index = g->Index + diff;
			diff = diff + c->Length - g->Length;
			Console::WriteLine(" {0}, {1}, diff = {2} ", g->Index, g->Length, diff);
			Writefile = Readfile->Remove(index, g->Length);
			Readfile = Writefile->Insert(index, c);
			
		};
		if (h->Value == "T_max") {
			index = g->Index + diff;
			diff = diff + d->Length - g->Length;
			Console::WriteLine(" {0}, {1}, diff = {2} ", g->Index, g->Length, diff);
			Writefile = Readfile->Remove(index, g->Length);
			Readfile = Writefile->Insert(index, d);
			
		};
		if (h->Value == "T_1") {
			index = g->Index + diff;
			diff = diff + e->Length - g->Length;
			Console::WriteLine(" {0}, {1}, diff = {2} ", g->Index, g->Length, diff);
			Writefile = Readfile->Remove(index, g->Length);
			Readfile = Writefile->Insert(index, e);
			
		};
		if (h->Value == "Time_1") {
			index = g->Index + diff;
			diff = diff + f->Length - g->Length;
			Console::WriteLine(" {0}, {1}, diff = {2} ", g->Index, g->Length, diff);
			Writefile = Readfile->Remove(index, g->Length);
			Readfile = Writefile->Insert(index, f);
			
		};
		m = m->NextMatch();

	}

	File::WriteAllText(strfilename, Readfile);

}
	   //Load Param
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

	openIni();
}
	   //Load Default Param
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	defaultIni();
}
	  
};
	};