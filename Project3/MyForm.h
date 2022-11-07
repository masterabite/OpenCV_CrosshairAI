#pragma once
#include <conio.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>

#define M_PI 3.1415926

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;

	private: System::Windows::Forms::Button^ button1;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::NumericUpDown^ numericUpDown5;
	private: System::Windows::Forms::Label^ label6;

	protected:
		bool loaded;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;

	protected:
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(449, 775);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, System::Int32::MinValue });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(60, 22);
			this->numericUpDown1->TabIndex = 0;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 80, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(449, 812);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, System::Int32::MinValue });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(60, 22);
			this->numericUpDown2->TabIndex = 1;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(307, 775);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 31);
			this->button1->TabIndex = 3;
			this->button1->Text = L"ќтрисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(429, 777);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"x";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(428, 812);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"y";
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(570, 777);
			this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->numericUpDown5->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(60, 22);
			this->numericUpDown5->TabIndex = 11;
			this->numericUpDown5->UseWaitCursor = true;
			this->numericUpDown5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 90, 0, 0, 0 });
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(528, 777);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 17);
			this->label6->TabIndex = 12;
			this->label6->Text = L"угол";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1920, 1280);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Image = gcnew Bitmap(256, 256);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(307, 812);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 31);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Rand";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(847, 853);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->numericUpDown5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Name = L"MyForm";
			this->Text = L"ƒемонстраци€ графики";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

		//проверка нахождени€ точки в квадрате размерами width height
		private: bool inSquare(float width, float height, PointF p) {
			return (p.X >= -width/2 && p.X <= width/2 && p.Y >= -height/2 && p.Y <= height/2);
		}

		private: int randRange(int min, int max) {
			return min + rand() % (max - min + 1);
		}

		private: Void drawLine(Graphics^ gr, Pen^ pen, PointF& center, float k, float b) {
			float width = pictureBox1->Size.Width;
			float height = pictureBox1->Size.Height;

			SizeF centerSize(center.X, center.Y);

			ArrayList arr;

			arr.Add(PointF(               -width/2,		-width / 2 * k + b));
			arr.Add(PointF(                width/2,		 width / 2 * k + b));
			arr.Add(PointF(  (-height / 2 - b) / k,		-height/2));
			arr.Add(PointF(   (height / 2 - b) / k,		 height/2));

			for (int i = 0; i < 4; ++i) {
				if (inSquare(width, height, (PointF)arr[i])) {
					for (int j = i + 1; j < 4; ++j) {
						if (inSquare(width, height, (PointF)arr[j])) {
							PointF p1 = PointF::Add((PointF)arr[i], centerSize);
							PointF p2 = PointF::Add((PointF)arr[j], centerSize);
						
							gr->DrawLine(pen, p1, p2);
							//printf("Drawed Line: y = %f*x + %f \t byPoints (%f, %f), (%f, %f)\n", k, b, p1.X, p1.Y, p2.X, p2.Y);
							return;
						}
					}
				}
			}
		}

		private: Void drawCrosshair(Graphics^ gr, Pen^ pen, PointF& center, PointF& point, float angle) {
			float
				k1 = tan((angle) / 180 * M_PI),
				k2 = tan((angle + 90) / 180 * M_PI),
				b1 = point.Y-k1*point.X,
				b2 = point.Y-k2*point.X;

			//printf("\nDraw crosshair:\n");
			drawLine(gr, pen, center, k1, b1);
			drawLine(gr, pen, center, k2, b2);

		}

		private: Void draw(Graphics^ gr, Pen^ pen, PointF& point, float angle) {
			
			float width = 256;
			float height = 256;

			//printf("width: %f;\theight: %f\n", width, height);

			PointF center(width/2, height/2);

			gr->Clear(Color::White);

			pen->Width = 1;
			pen->Color = Color::Black;
			drawCrosshair(gr, pen, center, PointF(0, 0), 0);

			pen->Width = 3;
			pen->Color = Color::Red;
			drawCrosshair(gr, pen, center, point, angle);

		}

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			loaded = true;
			float x =  Convert::ToDouble(numericUpDown1->Value);
			float y = -Convert::ToDouble(numericUpDown2->Value);
			float da = Convert::ToDouble(numericUpDown5->Value);
		}

	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ gr = Graphics::FromImage(pictureBox1->Image);
		Pen^ pen = gcnew Pen(Color::Black);

		int n = 1000;
		printf("saving...\n");
		std::ofstream fout("parametrs.txt");
		for (Int32 i = 0; i < n; ++i) {
			float x = randRange(-128, 128) * 1.0 + 1.0*randRange(0, 99)/100;
			float y = randRange(-128, 128) * 1.0 + 1.0 * randRange(0, 99) / 100;
			float da = randRange(0, 45) * 1.0 + 1.0 * randRange(0, 99) / 100;
			
			draw(gr, pen, PointF(x, y), da);

			String^ out = gcnew String("images\\image");
			out += i.ToString() + gcnew String(".jpg");
			if (pictureBox1->Image == nullptr) {
				printf("image is NULL!\n");
				continue;
			}
			fout << x << ' ' << y << ' ' << da << '\n';
			pictureBox1->Image->Save(out, Imaging::ImageFormat::Jpeg);
		}
		fout.close();
		printf("OK\n");
	}
};
}
