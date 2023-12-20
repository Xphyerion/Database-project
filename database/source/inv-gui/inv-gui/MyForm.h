#pragma once

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>

namespace invgui {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    private:
        System::ComponentModel::Container^ components;

    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Label^ label2;

    private:
        sql::Connection* con;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::Lime;
            this->button3->Location = System::Drawing::Point(43, 25);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(92, 70);
            this->button3->TabIndex = 0;
            this->button3->Text = L"connect";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // button4
            // 
            this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->button4->Location = System::Drawing::Point(182, 25);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(83, 70);
            this->button4->TabIndex = 1;
            this->button4->Text = L"disconnect";
            this->button4->UseVisualStyleBackColor = false;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
            this->label2->Location = System::Drawing::Point(86, 162);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(110, 13);
            this->label2->TabIndex = 2;
            this->label2->Text = L"status: not connected";
            // 
            // MyForm
            // 
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button3);
            this->Name = L"MyForm";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            sql::mysql::MySQL_Driver* driver;
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect("tcp://localhost:3306", "root", "");
            con->setSchema("inv_mgmt_db");

            label2->Text = "Status: Connected";
        }
        catch (sql::SQLException& ex) {
            std::cerr << "SQL Connection Error: " << ex.what() << std::endl;
            label2->Text = "Status: Connection Failed";
        }
    }

    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            delete con;
            label2->Text = "Status: Disconnected";
        }
        catch (sql::SQLException& ex) {
            std::cerr << "SQL Disconnection Error: " << ex.what() << std::endl;
            label2->Text = "Status: Disconnection Failed";
        }
    }
    };
}
