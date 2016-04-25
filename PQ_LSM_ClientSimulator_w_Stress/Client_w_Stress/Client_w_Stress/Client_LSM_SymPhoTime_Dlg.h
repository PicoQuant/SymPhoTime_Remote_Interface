#pragma once

namespace Client_w_Stress {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  using namespace System::Text;
  using namespace msclr::interop;

  
  long __stdcall MyParamCBFunc (char* pcIdent, float fValue, long iRecNr);

  #define STOP_FIRED_BY_USER       0
  #define STOP_FIRED_BY_TIMER     -1
  #define STOP_FIRED_BY_FEEDBACK   1

  /// <summary>
  /// Zusammenfassung für Client_LSM_SymPhoTime_Dlg
  /// </summary>
  public ref class Client_LSM_SymPhoTime_Dlg : public System::Windows::Forms::Form
  {
  public:
    Client_LSM_SymPhoTime_Dlg(void)
    {
      InitializeComponent();
      //
      //TODO: Konstruktorcode hier hinzufügen.
      //
    }
  protected:
    /// <summary>
    /// Verwendete Ressourcen bereinigen.
    /// </summary>
    ~Client_LSM_SymPhoTime_Dlg()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::GroupBox^  grpMandatory;
  private: System::Windows::Forms::RadioButton^  rbtnPointMeas;
  private: System::Windows::Forms::RadioButton^  rbtnImageScan;
  private: System::Windows::Forms::CheckBox^  chkTestMeas;
  private: System::Windows::Forms::Panel^  pnlScanDirection;
  private: System::Windows::Forms::RadioButton^  rbtnBiDirectional;
  private: System::Windows::Forms::RadioButton^  rbtnMonoDirectional;
  private: System::Windows::Forms::CheckBox^  chkSquare;
  private: System::Windows::Forms::Label^  lblTimes;
  private: System::Windows::Forms::NumericUpDown^  sedtPixY;
  private: System::Windows::Forms::Label^  lblPixels;
  private: System::Windows::Forms::NumericUpDown^  sedtPixX;
  private: System::Windows::Forms::ComboBox^  cbxResolUnit;
  private: System::Windows::Forms::Label^  lblSpatialResol;
  private: System::Windows::Forms::NumericUpDown^  sedtResol;
  private: System::Windows::Forms::GroupBox^  grpImgOptional;
  private: System::Windows::Forms::ComboBox^  cbxTimePerPixelUnit;
  private: System::Windows::Forms::NumericUpDown^  sedtTimePerPixel;
  private: System::Windows::Forms::CheckBox^  chkTimePerPixel;
  private: System::Windows::Forms::ComboBox^  cbxTimePerImageUnit;
  private: System::Windows::Forms::NumericUpDown^  sedtTimePerImage;
  private: System::Windows::Forms::CheckBox^  chkTimePerImage;
  private: System::Windows::Forms::GroupBox^  grpOptional;
  private: System::Windows::Forms::TextBox^  edtComment;
  private: System::Windows::Forms::TextBox^  edtGroupname;
  private: System::Windows::Forms::TextBox^  edtFilename;
  private: System::Windows::Forms::CheckBox^  chkComment;
  private: System::Windows::Forms::CheckBox^  chkGroupname;
  private: System::Windows::Forms::CheckBox^  chkFilename;
  private: System::Windows::Forms::GroupBox^  grpConnection;
  public protected: System::Windows::Forms::RadioButton^  rbtnOtherHost;
  public protected: System::Windows::Forms::RadioButton^  rbtnLocal;
  private: System::Windows::Forms::Label^  lblVersion;
  private: System::Windows::Forms::Label^  lblIPAdress;
  public protected: System::Windows::Forms::TextBox^  edtIPAdrFld4;
  public protected: System::Windows::Forms::TextBox^  edtIPAdrFld3;
  private: System::Windows::Forms::Label^  lblIPAdrSep3;
  public protected: System::Windows::Forms::TextBox^  edtIPAdrFld2;
  private: System::Windows::Forms::Label^  lblIPAdrSep2;
  public protected: System::Windows::Forms::TextBox^  edtIPAdrFld1;
  private: System::Windows::Forms::Label^  lblIPAdrSep1;
  private: System::Windows::Forms::NumericUpDown^  sedtPort;
  private: System::Windows::Forms::Label^  lblPort;
  private: System::Windows::Forms::TextBox^  edtState;
  private: System::Windows::Forms::Label^  lblState;
  private: System::Windows::Forms::Button^  btnInitConnection;
  private: System::Windows::Forms::Label^  lblDLLVersionTitle;
  private: System::Windows::Forms::Label^  lblDLLVersion;
  private: System::Windows::Forms::Button^  btnToggleLogWin;
  private: System::Windows::Forms::Label^  lblSPTVersionTitle;
  public protected: System::Windows::Forms::Label^  lblSPTVersion;
  public protected: System::Windows::Forms::TextBox^  memoResults;
  private: System::Windows::Forms::Timer^  tmrStatusPoll;
  private:
    /// <summary>
    /// Erforderliche Designervariable.
    /// </summary>
  private: System::ComponentModel::IContainer^  components;

  private: bool bLoaded;
  private: bool bIPAdressKeyNotAllowed;

  public:  long iLastNonLocalIP;
  public:  System::String^ strLogFileName;
  public:  long iStopFired;
  public:  bool bSyncServerVersion;
  public:  System::String^ strServerVersion;
  public:  bool bSyncResultMemo;
  public:  System::String^ strResultMemo;

  private: System::String^ strSPT_RI_STATUS_UNKNOWN;
  private: System::String^ strSPT_RI_STATUS_IDLE;
  private: System::String^ strSPT_RI_STATUS_MEAS_RUNNING;
  private: System::String^ strSPT_RI_STATUS_MEAS_TERMINATING;

  private: System::Windows::Forms::Button^  btnClear;
  private: System::Windows::Forms::GroupBox^  grpMeasurement;
  private: System::Windows::Forms::Button^  btnStopMeas;
  private: System::Windows::Forms::Button^  btnStartMeas;
  private: System::Windows::Forms::NumericUpDown^  sedtAutoStopTime;
  private: System::Windows::Forms::Label^  lblSeconds;
  private: System::Windows::Forms::CheckBox^  chkAutoStop;
  private: System::Windows::Forms::Label^  lblProtocoll;
  private: System::Windows::Forms::Timer^  tmrAutoStop;
  private: System::Windows::Forms::CheckBox^  chkRestart;
  private: System::Windows::Forms::Label^  lblNACKRec;
  public protected: System::Windows::Forms::CheckBox^  chkFeedbackConditionedStop;
  public protected: System::Windows::Forms::NumericUpDown^  sedtNACKRecords;
  public protected: System::Windows::Forms::ComboBox^  cbxStopReason;
  private: System::Windows::Forms::Timer^  tmrSynchronize;
public protected: 

  private: TReceiveParamFunc ParamCBFunc;
  public:  System::Void rbtnLocal_InvokeCheckedChanged() {
          System::EventArgs^  e;
          Client_LSM_SymPhoTime_Dlg::rbtnLocal_CheckedChanged (this->rbtnOtherHost, e);
        }


#pragma region Windows Form Designer generated code
    /// <summary>
    /// Erforderliche Methode für die Designerunterstützung.
    /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
    /// </summary>
    void InitializeComponent(void)
    {
      this->components = (gcnew System::ComponentModel::Container());
      System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Client_LSM_SymPhoTime_Dlg::typeid));
      this->grpMandatory = (gcnew System::Windows::Forms::GroupBox());
      this->sedtPixX = (gcnew System::Windows::Forms::NumericUpDown());
      this->cbxResolUnit = (gcnew System::Windows::Forms::ComboBox());
      this->lblSpatialResol = (gcnew System::Windows::Forms::Label());
      this->sedtResol = (gcnew System::Windows::Forms::NumericUpDown());
      this->chkSquare = (gcnew System::Windows::Forms::CheckBox());
      this->sedtPixY = (gcnew System::Windows::Forms::NumericUpDown());
      this->lblPixels = (gcnew System::Windows::Forms::Label());
      this->pnlScanDirection = (gcnew System::Windows::Forms::Panel());
      this->rbtnBiDirectional = (gcnew System::Windows::Forms::RadioButton());
      this->rbtnMonoDirectional = (gcnew System::Windows::Forms::RadioButton());
      this->rbtnPointMeas = (gcnew System::Windows::Forms::RadioButton());
      this->rbtnImageScan = (gcnew System::Windows::Forms::RadioButton());
      this->chkTestMeas = (gcnew System::Windows::Forms::CheckBox());
      this->lblTimes = (gcnew System::Windows::Forms::Label());
      this->grpImgOptional = (gcnew System::Windows::Forms::GroupBox());
      this->cbxTimePerImageUnit = (gcnew System::Windows::Forms::ComboBox());
      this->sedtTimePerImage = (gcnew System::Windows::Forms::NumericUpDown());
      this->chkTimePerImage = (gcnew System::Windows::Forms::CheckBox());
      this->cbxTimePerPixelUnit = (gcnew System::Windows::Forms::ComboBox());
      this->sedtTimePerPixel = (gcnew System::Windows::Forms::NumericUpDown());
      this->chkTimePerPixel = (gcnew System::Windows::Forms::CheckBox());
      this->grpOptional = (gcnew System::Windows::Forms::GroupBox());
      this->edtComment = (gcnew System::Windows::Forms::TextBox());
      this->edtGroupname = (gcnew System::Windows::Forms::TextBox());
      this->edtFilename = (gcnew System::Windows::Forms::TextBox());
      this->chkComment = (gcnew System::Windows::Forms::CheckBox());
      this->chkGroupname = (gcnew System::Windows::Forms::CheckBox());
      this->chkFilename = (gcnew System::Windows::Forms::CheckBox());
      this->grpConnection = (gcnew System::Windows::Forms::GroupBox());
      this->edtState = (gcnew System::Windows::Forms::TextBox());
      this->lblState = (gcnew System::Windows::Forms::Label());
      this->btnInitConnection = (gcnew System::Windows::Forms::Button());
      this->sedtPort = (gcnew System::Windows::Forms::NumericUpDown());
      this->lblPort = (gcnew System::Windows::Forms::Label());
      this->edtIPAdrFld4 = (gcnew System::Windows::Forms::TextBox());
      this->edtIPAdrFld3 = (gcnew System::Windows::Forms::TextBox());
      this->lblIPAdrSep3 = (gcnew System::Windows::Forms::Label());
      this->edtIPAdrFld2 = (gcnew System::Windows::Forms::TextBox());
      this->lblIPAdrSep2 = (gcnew System::Windows::Forms::Label());
      this->edtIPAdrFld1 = (gcnew System::Windows::Forms::TextBox());
      this->lblIPAdrSep1 = (gcnew System::Windows::Forms::Label());
      this->lblIPAdress = (gcnew System::Windows::Forms::Label());
      this->rbtnOtherHost = (gcnew System::Windows::Forms::RadioButton());
      this->rbtnLocal = (gcnew System::Windows::Forms::RadioButton());
      this->lblVersion = (gcnew System::Windows::Forms::Label());
      this->lblDLLVersionTitle = (gcnew System::Windows::Forms::Label());
      this->lblDLLVersion = (gcnew System::Windows::Forms::Label());
      this->btnToggleLogWin = (gcnew System::Windows::Forms::Button());
      this->lblSPTVersion = (gcnew System::Windows::Forms::Label());
      this->lblSPTVersionTitle = (gcnew System::Windows::Forms::Label());
      this->memoResults = (gcnew System::Windows::Forms::TextBox());
      this->tmrStatusPoll = (gcnew System::Windows::Forms::Timer(this->components));
      this->btnClear = (gcnew System::Windows::Forms::Button());
      this->grpMeasurement = (gcnew System::Windows::Forms::GroupBox());
      this->cbxStopReason = (gcnew System::Windows::Forms::ComboBox());
      this->lblNACKRec = (gcnew System::Windows::Forms::Label());
      this->sedtNACKRecords = (gcnew System::Windows::Forms::NumericUpDown());
      this->chkFeedbackConditionedStop = (gcnew System::Windows::Forms::CheckBox());
      this->chkRestart = (gcnew System::Windows::Forms::CheckBox());
      this->btnStopMeas = (gcnew System::Windows::Forms::Button());
      this->sedtAutoStopTime = (gcnew System::Windows::Forms::NumericUpDown());
      this->lblSeconds = (gcnew System::Windows::Forms::Label());
      this->chkAutoStop = (gcnew System::Windows::Forms::CheckBox());
      this->btnStartMeas = (gcnew System::Windows::Forms::Button());
      this->lblProtocoll = (gcnew System::Windows::Forms::Label());
      this->tmrAutoStop = (gcnew System::Windows::Forms::Timer(this->components));
      this->tmrSynchronize = (gcnew System::Windows::Forms::Timer(this->components));
      this->grpMandatory->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtPixX))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtResol))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtPixY))->BeginInit();
      this->pnlScanDirection->SuspendLayout();
      this->grpImgOptional->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtTimePerImage))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtTimePerPixel))->BeginInit();
      this->grpOptional->SuspendLayout();
      this->grpConnection->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtPort))->BeginInit();
      this->grpMeasurement->SuspendLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtNACKRecords))->BeginInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtAutoStopTime))->BeginInit();
      this->SuspendLayout();
      // 
      // grpMandatory
      // 
      this->grpMandatory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->grpMandatory->Controls->Add(this->sedtPixX);
      this->grpMandatory->Controls->Add(this->cbxResolUnit);
      this->grpMandatory->Controls->Add(this->lblSpatialResol);
      this->grpMandatory->Controls->Add(this->sedtResol);
      this->grpMandatory->Controls->Add(this->chkSquare);
      this->grpMandatory->Controls->Add(this->sedtPixY);
      this->grpMandatory->Controls->Add(this->lblPixels);
      this->grpMandatory->Controls->Add(this->pnlScanDirection);
      this->grpMandatory->Controls->Add(this->rbtnPointMeas);
      this->grpMandatory->Controls->Add(this->rbtnImageScan);
      this->grpMandatory->Controls->Add(this->chkTestMeas);
      this->grpMandatory->Controls->Add(this->lblTimes);
      this->grpMandatory->Location = System::Drawing::Point(24, 32);
      this->grpMandatory->Name = L"grpMandatory";
      this->grpMandatory->Size = System::Drawing::Size(423, 114);
      this->grpMandatory->TabIndex = 0;
      this->grpMandatory->TabStop = false;
      this->grpMandatory->Text = L"   Mandatory   ";
      // 
      // sedtPixX
      // 
      this->sedtPixX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->sedtPixX->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->sedtPixX->Location = System::Drawing::Point(284, 41);
      this->sedtPixX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {512, 0, 0, 0});
      this->sedtPixX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {16, 0, 0, 0});
      this->sedtPixX->Name = L"sedtPixX";
      this->sedtPixX->Size = System::Drawing::Size(44, 20);
      this->sedtPixX->TabIndex = 6;
      this->sedtPixX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
      this->sedtPixX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {64, 0, 0, 0});
      this->sedtPixX->ValueChanged += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::sedtPixX_ValueChanged);
      // 
      // cbxResolUnit
      // 
      this->cbxResolUnit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->cbxResolUnit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
      this->cbxResolUnit->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->cbxResolUnit->FormattingEnabled = true;
      this->cbxResolUnit->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"mm", L"µm", L"nm"});
      this->cbxResolUnit->Location = System::Drawing::Point(329, 85);
      this->cbxResolUnit->Name = L"cbxResolUnit";
      this->cbxResolUnit->Size = System::Drawing::Size(42, 22);
      this->cbxResolUnit->TabIndex = 13;
      // 
      // lblSpatialResol
      // 
      this->lblSpatialResol->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->lblSpatialResol->AutoSize = true;
      this->lblSpatialResol->Location = System::Drawing::Point(163, 88);
      this->lblSpatialResol->Name = L"lblSpatialResol";
      this->lblSpatialResol->Size = System::Drawing::Size(95, 14);
      this->lblSpatialResol->TabIndex = 12;
      this->lblSpatialResol->Text = L"Spatial Resolution:";
      // 
      // sedtResol
      // 
      this->sedtResol->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->sedtResol->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->sedtResol->Location = System::Drawing::Point(284, 86);
      this->sedtResol->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {999, 0, 0, 0});
      this->sedtResol->Name = L"sedtResol";
      this->sedtResol->Size = System::Drawing::Size(44, 20);
      this->sedtResol->TabIndex = 11;
      this->sedtResol->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
      this->sedtResol->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {32, 0, 0, 0});
      // 
      // chkSquare
      // 
      this->chkSquare->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->chkSquare->Checked = true;
      this->chkSquare->CheckState = System::Windows::Forms::CheckState::Checked;
      this->chkSquare->Location = System::Drawing::Point(165, 44);
      this->chkSquare->Name = L"chkSquare";
      this->chkSquare->Size = System::Drawing::Size(76, 17);
      this->chkSquare->TabIndex = 10;
      this->chkSquare->Text = L"Square";
      this->chkSquare->UseVisualStyleBackColor = true;
      this->chkSquare->CheckedChanged += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::chkSquare_CheckedChanged);
      // 
      // sedtPixY
      // 
      this->sedtPixY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->sedtPixY->Enabled = false;
      this->sedtPixY->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->sedtPixY->Location = System::Drawing::Point(352, 41);
      this->sedtPixY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {512, 0, 0, 0});
      this->sedtPixY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {16, 0, 0, 0});
      this->sedtPixY->Name = L"sedtPixY";
      this->sedtPixY->Size = System::Drawing::Size(44, 20);
      this->sedtPixY->TabIndex = 8;
      this->sedtPixY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
      this->sedtPixY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {64, 0, 0, 0});
      // 
      // lblPixels
      // 
      this->lblPixels->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->lblPixels->AutoSize = true;
      this->lblPixels->Location = System::Drawing::Point(247, 46);
      this->lblPixels->Name = L"lblPixels";
      this->lblPixels->Size = System::Drawing::Size(38, 14);
      this->lblPixels->TabIndex = 7;
      this->lblPixels->Text = L"Pixels:";
      // 
      // pnlScanDirection
      // 
      this->pnlScanDirection->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->pnlScanDirection->Controls->Add(this->rbtnBiDirectional);
      this->pnlScanDirection->Controls->Add(this->rbtnMonoDirectional);
      this->pnlScanDirection->Location = System::Drawing::Point(153, 65);
      this->pnlScanDirection->Name = L"pnlScanDirection";
      this->pnlScanDirection->Size = System::Drawing::Size(219, 19);
      this->pnlScanDirection->TabIndex = 5;
      // 
      // rbtnBiDirectional
      // 
      this->rbtnBiDirectional->AutoSize = true;
      this->rbtnBiDirectional->Location = System::Drawing::Point(138, 1);
      this->rbtnBiDirectional->Name = L"rbtnBiDirectional";
      this->rbtnBiDirectional->Size = System::Drawing::Size(83, 18);
      this->rbtnBiDirectional->TabIndex = 6;
      this->rbtnBiDirectional->Text = L"Bidirectional";
      this->rbtnBiDirectional->UseVisualStyleBackColor = true;
      // 
      // rbtnMonoDirectional
      // 
      this->rbtnMonoDirectional->AutoSize = true;
      this->rbtnMonoDirectional->Checked = true;
      this->rbtnMonoDirectional->Location = System::Drawing::Point(13, 1);
      this->rbtnMonoDirectional->Name = L"rbtnMonoDirectional";
      this->rbtnMonoDirectional->Size = System::Drawing::Size(100, 18);
      this->rbtnMonoDirectional->TabIndex = 5;
      this->rbtnMonoDirectional->TabStop = true;
      this->rbtnMonoDirectional->Text = L"Monodirectional";
      this->rbtnMonoDirectional->UseVisualStyleBackColor = true;
      // 
      // rbtnPointMeas
      // 
      this->rbtnPointMeas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->rbtnPointMeas->AutoSize = true;
      this->rbtnPointMeas->Location = System::Drawing::Point(290, 20);
      this->rbtnPointMeas->Name = L"rbtnPointMeas";
      this->rbtnPointMeas->Size = System::Drawing::Size(116, 17);
      this->rbtnPointMeas->TabIndex = 2;
      this->rbtnPointMeas->Text = L"Point Measurement";
      this->rbtnPointMeas->UseVisualStyleBackColor = true;
      // 
      // rbtnImageScan
      // 
      this->rbtnImageScan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->rbtnImageScan->AutoSize = true;
      this->rbtnImageScan->Checked = true;
      this->rbtnImageScan->Location = System::Drawing::Point(165, 20);
      this->rbtnImageScan->Name = L"rbtnImageScan";
      this->rbtnImageScan->Size = System::Drawing::Size(82, 17);
      this->rbtnImageScan->TabIndex = 1;
      this->rbtnImageScan->TabStop = true;
      this->rbtnImageScan->Text = L"Image Scan";
      this->rbtnImageScan->UseVisualStyleBackColor = true;
      this->rbtnImageScan->CheckedChanged += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::rbtnImageScan_CheckedChanged);
      // 
      // chkTestMeas
      // 
      this->chkTestMeas->AutoSize = true;
      this->chkTestMeas->Location = System::Drawing::Point(17, 20);
      this->chkTestMeas->Name = L"chkTestMeas";
      this->chkTestMeas->Size = System::Drawing::Size(114, 17);
      this->chkTestMeas->TabIndex = 0;
      this->chkTestMeas->Text = L"Test Measurement";
      this->chkTestMeas->UseVisualStyleBackColor = true;
      // 
      // lblTimes
      // 
      this->lblTimes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->lblTimes->AutoSize = true;
      this->lblTimes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->lblTimes->Location = System::Drawing::Point(333, 43);
      this->lblTimes->Name = L"lblTimes";
      this->lblTimes->Size = System::Drawing::Size(14, 16);
      this->lblTimes->TabIndex = 9;
      this->lblTimes->Text = L"x";
      // 
      // grpImgOptional
      // 
      this->grpImgOptional->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->grpImgOptional->Controls->Add(this->cbxTimePerImageUnit);
      this->grpImgOptional->Controls->Add(this->sedtTimePerImage);
      this->grpImgOptional->Controls->Add(this->chkTimePerImage);
      this->grpImgOptional->Controls->Add(this->cbxTimePerPixelUnit);
      this->grpImgOptional->Controls->Add(this->sedtTimePerPixel);
      this->grpImgOptional->Controls->Add(this->chkTimePerPixel);
      this->grpImgOptional->Location = System::Drawing::Point(24, 154);
      this->grpImgOptional->Name = L"grpImgOptional";
      this->grpImgOptional->Size = System::Drawing::Size(423, 72);
      this->grpImgOptional->TabIndex = 1;
      this->grpImgOptional->TabStop = false;
      this->grpImgOptional->Text = L"   Optional (Image Only)   ";
      // 
      // cbxTimePerImageUnit
      // 
      this->cbxTimePerImageUnit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->cbxTimePerImageUnit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
      this->cbxTimePerImageUnit->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->cbxTimePerImageUnit->FormattingEnabled = true;
      this->cbxTimePerImageUnit->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"s", L"ms", L"µs"});
      this->cbxTimePerImageUnit->Location = System::Drawing::Point(329, 43);
      this->cbxTimePerImageUnit->Name = L"cbxTimePerImageUnit";
      this->cbxTimePerImageUnit->Size = System::Drawing::Size(42, 22);
      this->cbxTimePerImageUnit->TabIndex = 18;
      // 
      // sedtTimePerImage
      // 
      this->sedtTimePerImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->sedtTimePerImage->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->sedtTimePerImage->Location = System::Drawing::Point(284, 44);
      this->sedtTimePerImage->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {999, 0, 0, 0});
      this->sedtTimePerImage->Name = L"sedtTimePerImage";
      this->sedtTimePerImage->Size = System::Drawing::Size(44, 20);
      this->sedtTimePerImage->TabIndex = 17;
      this->sedtTimePerImage->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
      // 
      // chkTimePerImage
      // 
      this->chkTimePerImage->AutoSize = true;
      this->chkTimePerImage->Location = System::Drawing::Point(17, 45);
      this->chkTimePerImage->Name = L"chkTimePerImage";
      this->chkTimePerImage->Size = System::Drawing::Size(153, 17);
      this->chkTimePerImage->TabIndex = 16;
      this->chkTimePerImage->Text = L"Time per Image (estimated)";
      this->chkTimePerImage->UseVisualStyleBackColor = true;
      // 
      // cbxTimePerPixelUnit
      // 
      this->cbxTimePerPixelUnit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->cbxTimePerPixelUnit->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
      this->cbxTimePerPixelUnit->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->cbxTimePerPixelUnit->FormattingEnabled = true;
      this->cbxTimePerPixelUnit->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"ms", L"µs"});
      this->cbxTimePerPixelUnit->Location = System::Drawing::Point(329, 19);
      this->cbxTimePerPixelUnit->Name = L"cbxTimePerPixelUnit";
      this->cbxTimePerPixelUnit->Size = System::Drawing::Size(42, 22);
      this->cbxTimePerPixelUnit->TabIndex = 15;
      // 
      // sedtTimePerPixel
      // 
      this->sedtTimePerPixel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->sedtTimePerPixel->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->sedtTimePerPixel->Location = System::Drawing::Point(284, 20);
      this->sedtTimePerPixel->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {999, 0, 0, 0});
      this->sedtTimePerPixel->Name = L"sedtTimePerPixel";
      this->sedtTimePerPixel->Size = System::Drawing::Size(44, 20);
      this->sedtTimePerPixel->TabIndex = 14;
      this->sedtTimePerPixel->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
      // 
      // chkTimePerPixel
      // 
      this->chkTimePerPixel->AutoSize = true;
      this->chkTimePerPixel->Location = System::Drawing::Point(17, 22);
      this->chkTimePerPixel->Name = L"chkTimePerPixel";
      this->chkTimePerPixel->Size = System::Drawing::Size(92, 17);
      this->chkTimePerPixel->TabIndex = 1;
      this->chkTimePerPixel->Text = L"Time per Pixel";
      this->chkTimePerPixel->UseVisualStyleBackColor = true;
      // 
      // grpOptional
      // 
      this->grpOptional->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->grpOptional->Controls->Add(this->edtComment);
      this->grpOptional->Controls->Add(this->edtGroupname);
      this->grpOptional->Controls->Add(this->edtFilename);
      this->grpOptional->Controls->Add(this->chkComment);
      this->grpOptional->Controls->Add(this->chkGroupname);
      this->grpOptional->Controls->Add(this->chkFilename);
      this->grpOptional->Location = System::Drawing::Point(24, 235);
      this->grpOptional->Name = L"grpOptional";
      this->grpOptional->Size = System::Drawing::Size(423, 125);
      this->grpOptional->TabIndex = 2;
      this->grpOptional->TabStop = false;
      this->grpOptional->Text = L"   Optional  (exemplarly; others could easily be added…)   ";
      // 
      // edtComment
      // 
      this->edtComment->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->edtComment->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->edtComment->Location = System::Drawing::Point(110, 66);
      this->edtComment->Multiline = true;
      this->edtComment->Name = L"edtComment";
      this->edtComment->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
      this->edtComment->Size = System::Drawing::Size(306, 49);
      this->edtComment->TabIndex = 7;
      // 
      // edtGroupname
      // 
      this->edtGroupname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->edtGroupname->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->edtGroupname->Location = System::Drawing::Point(110, 43);
      this->edtGroupname->Name = L"edtGroupname";
      this->edtGroupname->Size = System::Drawing::Size(306, 20);
      this->edtGroupname->TabIndex = 6;
      // 
      // edtFilename
      // 
      this->edtFilename->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->edtFilename->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->edtFilename->Location = System::Drawing::Point(110, 20);
      this->edtFilename->Name = L"edtFilename";
      this->edtFilename->Size = System::Drawing::Size(306, 20);
      this->edtFilename->TabIndex = 5;
      // 
      // chkComment
      // 
      this->chkComment->Location = System::Drawing::Point(17, 67);
      this->chkComment->Name = L"chkComment";
      this->chkComment->Size = System::Drawing::Size(88, 17);
      this->chkComment->TabIndex = 4;
      this->chkComment->Text = L"Comment";
      this->chkComment->UseVisualStyleBackColor = true;
      // 
      // chkGroupname
      // 
      this->chkGroupname->Location = System::Drawing::Point(17, 45);
      this->chkGroupname->Name = L"chkGroupname";
      this->chkGroupname->Size = System::Drawing::Size(88, 17);
      this->chkGroupname->TabIndex = 3;
      this->chkGroupname->Text = L"Groupname";
      this->chkGroupname->UseVisualStyleBackColor = true;
      // 
      // chkFilename
      // 
      this->chkFilename->Location = System::Drawing::Point(17, 23);
      this->chkFilename->Name = L"chkFilename";
      this->chkFilename->Size = System::Drawing::Size(88, 17);
      this->chkFilename->TabIndex = 2;
      this->chkFilename->Text = L"Filename";
      this->chkFilename->UseVisualStyleBackColor = true;
      // 
      // grpConnection
      // 
      this->grpConnection->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->grpConnection->Controls->Add(this->edtState);
      this->grpConnection->Controls->Add(this->lblState);
      this->grpConnection->Controls->Add(this->btnInitConnection);
      this->grpConnection->Controls->Add(this->sedtPort);
      this->grpConnection->Controls->Add(this->lblPort);
      this->grpConnection->Controls->Add(this->edtIPAdrFld4);
      this->grpConnection->Controls->Add(this->edtIPAdrFld3);
      this->grpConnection->Controls->Add(this->lblIPAdrSep3);
      this->grpConnection->Controls->Add(this->edtIPAdrFld2);
      this->grpConnection->Controls->Add(this->lblIPAdrSep2);
      this->grpConnection->Controls->Add(this->edtIPAdrFld1);
      this->grpConnection->Controls->Add(this->lblIPAdrSep1);
      this->grpConnection->Controls->Add(this->lblIPAdress);
      this->grpConnection->Controls->Add(this->rbtnOtherHost);
      this->grpConnection->Controls->Add(this->rbtnLocal);
      this->grpConnection->Location = System::Drawing::Point(24, 368);
      this->grpConnection->Name = L"grpConnection";
      this->grpConnection->Size = System::Drawing::Size(423, 69);
      this->grpConnection->TabIndex = 3;
      this->grpConnection->TabStop = false;
      this->grpConnection->Text = L"   Host / Connection   ";
      // 
      // edtState
      // 
      this->edtState->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->edtState->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold));
      this->edtState->Location = System::Drawing::Point(229, 41);
      this->edtState->Name = L"edtState";
      this->edtState->ReadOnly = true;
      this->edtState->Size = System::Drawing::Size(187, 20);
      this->edtState->TabIndex = 23;
      this->edtState->Text = L"\?\?\?";
      this->edtState->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
      this->edtState->TextChanged += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtState_TextChanged);
      // 
      // lblState
      // 
      this->lblState->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->lblState->AutoSize = true;
      this->lblState->Location = System::Drawing::Point(135, 44);
      this->lblState->Name = L"lblState";
      this->lblState->Size = System::Drawing::Size(92, 14);
      this->lblState->TabIndex = 22;
      this->lblState->Text = L"Connection State:";
      this->lblState->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
      // 
      // btnInitConnection
      // 
      this->btnInitConnection->Location = System::Drawing::Point(17, 39);
      this->btnInitConnection->Name = L"btnInitConnection";
      this->btnInitConnection->Size = System::Drawing::Size(93, 24);
      this->btnInitConnection->TabIndex = 21;
      this->btnInitConnection->Text = L"Init &Connection";
      this->btnInitConnection->UseVisualStyleBackColor = true;
      this->btnInitConnection->Click += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::btnInitConnection_Click);
      // 
      // sedtPort
      // 
      this->sedtPort->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->sedtPort->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->sedtPort->Location = System::Drawing::Point(358, 12);
      this->sedtPort->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65535, 0, 0, 0});
      this->sedtPort->Name = L"sedtPort";
      this->sedtPort->Size = System::Drawing::Size(58, 20);
      this->sedtPort->TabIndex = 19;
      this->sedtPort->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
      this->sedtPort->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {6000, 0, 0, 0});
      // 
      // lblPort
      // 
      this->lblPort->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->lblPort->Location = System::Drawing::Point(326, 16);
      this->lblPort->Name = L"lblPort";
      this->lblPort->Size = System::Drawing::Size(35, 14);
      this->lblPort->TabIndex = 20;
      this->lblPort->Text = L"; Port:";
      this->lblPort->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
      // 
      // edtIPAdrFld4
      // 
      this->edtIPAdrFld4->Enabled = false;
      this->edtIPAdrFld4->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->edtIPAdrFld4->Location = System::Drawing::Point(200, 13);
      this->edtIPAdrFld4->MaxLength = 3;
      this->edtIPAdrFld4->Name = L"edtIPAdrFld4";
      this->edtIPAdrFld4->Size = System::Drawing::Size(27, 20);
      this->edtIPAdrFld4->TabIndex = 18;
      this->edtIPAdrFld4->Text = L"3";
      this->edtIPAdrFld4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
      this->edtIPAdrFld4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyDown);
      this->edtIPAdrFld4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyPress);
      this->edtIPAdrFld4->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyUp);
      this->edtIPAdrFld4->Leave += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_Leave);
      // 
      // edtIPAdrFld3
      // 
      this->edtIPAdrFld3->Enabled = false;
      this->edtIPAdrFld3->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->edtIPAdrFld3->Location = System::Drawing::Point(165, 13);
      this->edtIPAdrFld3->MaxLength = 3;
      this->edtIPAdrFld3->Name = L"edtIPAdrFld3";
      this->edtIPAdrFld3->Size = System::Drawing::Size(27, 20);
      this->edtIPAdrFld3->TabIndex = 16;
      this->edtIPAdrFld3->Text = L"43";
      this->edtIPAdrFld3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
      this->edtIPAdrFld3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyDown);
      this->edtIPAdrFld3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyPress);
      this->edtIPAdrFld3->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyUp);
      this->edtIPAdrFld3->Leave += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_Leave);
      // 
      // lblIPAdrSep3
      // 
      this->lblIPAdrSep3->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->lblIPAdrSep3->Location = System::Drawing::Point(192, 17);
      this->lblIPAdrSep3->Name = L"lblIPAdrSep3";
      this->lblIPAdrSep3->Size = System::Drawing::Size(8, 13);
      this->lblIPAdrSep3->TabIndex = 17;
      this->lblIPAdrSep3->Text = L".";
      this->lblIPAdrSep3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      // 
      // edtIPAdrFld2
      // 
      this->edtIPAdrFld2->Enabled = false;
      this->edtIPAdrFld2->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->edtIPAdrFld2->Location = System::Drawing::Point(129, 13);
      this->edtIPAdrFld2->MaxLength = 3;
      this->edtIPAdrFld2->Name = L"edtIPAdrFld2";
      this->edtIPAdrFld2->Size = System::Drawing::Size(27, 20);
      this->edtIPAdrFld2->TabIndex = 14;
      this->edtIPAdrFld2->Text = L"168";
      this->edtIPAdrFld2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
      this->edtIPAdrFld2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyDown);
      this->edtIPAdrFld2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyPress);
      this->edtIPAdrFld2->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyUp);
      this->edtIPAdrFld2->Leave += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_Leave);
      // 
      // lblIPAdrSep2
      // 
      this->lblIPAdrSep2->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->lblIPAdrSep2->Location = System::Drawing::Point(156, 17);
      this->lblIPAdrSep2->Name = L"lblIPAdrSep2";
      this->lblIPAdrSep2->Size = System::Drawing::Size(8, 13);
      this->lblIPAdrSep2->TabIndex = 15;
      this->lblIPAdrSep2->Text = L".";
      this->lblIPAdrSep2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      // 
      // edtIPAdrFld1
      // 
      this->edtIPAdrFld1->Enabled = false;
      this->edtIPAdrFld1->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->edtIPAdrFld1->Location = System::Drawing::Point(94, 13);
      this->edtIPAdrFld1->MaxLength = 3;
      this->edtIPAdrFld1->Name = L"edtIPAdrFld1";
      this->edtIPAdrFld1->Size = System::Drawing::Size(27, 20);
      this->edtIPAdrFld1->TabIndex = 12;
      this->edtIPAdrFld1->Text = L"192";
      this->edtIPAdrFld1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
      this->edtIPAdrFld1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyDown);
      this->edtIPAdrFld1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyPress);
      this->edtIPAdrFld1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_KeyUp);
      this->edtIPAdrFld1->Leave += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::edtIPAdrFld_Leave);
      // 
      // lblIPAdrSep1
      // 
      this->lblIPAdrSep1->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->lblIPAdrSep1->Location = System::Drawing::Point(121, 17);
      this->lblIPAdrSep1->Name = L"lblIPAdrSep1";
      this->lblIPAdrSep1->Size = System::Drawing::Size(8, 13);
      this->lblIPAdrSep1->TabIndex = 13;
      this->lblIPAdrSep1->Text = L".";
      this->lblIPAdrSep1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      // 
      // lblIPAdress
      // 
      this->lblIPAdress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->lblIPAdress->Location = System::Drawing::Point(238, 16);
      this->lblIPAdress->Margin = System::Windows::Forms::Padding(0);
      this->lblIPAdress->Name = L"lblIPAdress";
      this->lblIPAdress->Size = System::Drawing::Size(93, 14);
      this->lblIPAdress->TabIndex = 11;
      this->lblIPAdress->Text = L"127.0.0.1";
      this->lblIPAdress->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
      // 
      // rbtnOtherHost
      // 
      this->rbtnOtherHost->AutoSize = true;
      this->rbtnOtherHost->Location = System::Drawing::Point(73, 17);
      this->rbtnOtherHost->Name = L"rbtnOtherHost";
      this->rbtnOtherHost->Size = System::Drawing::Size(14, 13);
      this->rbtnOtherHost->TabIndex = 8;
      this->rbtnOtherHost->UseVisualStyleBackColor = true;
      // 
      // rbtnLocal
      // 
      this->rbtnLocal->AutoSize = true;
      this->rbtnLocal->Checked = true;
      this->rbtnLocal->Location = System::Drawing::Point(17, 14);
      this->rbtnLocal->Name = L"rbtnLocal";
      this->rbtnLocal->Size = System::Drawing::Size(47, 17);
      this->rbtnLocal->TabIndex = 7;
      this->rbtnLocal->TabStop = true;
      this->rbtnLocal->Text = L"local";
      this->rbtnLocal->UseVisualStyleBackColor = true;
      this->rbtnLocal->CheckedChanged += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::rbtnLocal_CheckedChanged);
      // 
      // lblVersion
      // 
      this->lblVersion->AutoSize = true;
      this->lblVersion->Location = System::Drawing::Point(90, 6);
      this->lblVersion->MinimumSize = System::Drawing::Size(35, 14);
      this->lblVersion->Name = L"lblVersion";
      this->lblVersion->Size = System::Drawing::Size(35, 14);
      this->lblVersion->TabIndex = 4;
      // 
      // lblDLLVersionTitle
      // 
      this->lblDLLVersionTitle->AutoSize = true;
      this->lblDLLVersionTitle->Location = System::Drawing::Point(23, 2);
      this->lblDLLVersionTitle->Name = L"lblDLLVersionTitle";
      this->lblDLLVersionTitle->Size = System::Drawing::Size(70, 14);
      this->lblDLLVersionTitle->TabIndex = 22;
      this->lblDLLVersionTitle->Text = L"DLL-Version:";
      this->lblDLLVersionTitle->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
      // 
      // lblDLLVersion
      // 
      this->lblDLLVersion->Location = System::Drawing::Point(94, 2);
      this->lblDLLVersion->Name = L"lblDLLVersion";
      this->lblDLLVersion->Size = System::Drawing::Size(110, 14);
      this->lblDLLVersion->TabIndex = 23;
      this->lblDLLVersion->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
      // 
      // btnToggleLogWin
      // 
      this->btnToggleLogWin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->btnToggleLogWin->Location = System::Drawing::Point(333, 4);
      this->btnToggleLogWin->Name = L"btnToggleLogWin";
      this->btnToggleLogWin->Size = System::Drawing::Size(114, 24);
      this->btnToggleLogWin->TabIndex = 24;
      this->btnToggleLogWin->Tag = L"0";
      this->btnToggleLogWin->Text = L"Show &Log-Window";
      this->btnToggleLogWin->UseVisualStyleBackColor = true;
      this->btnToggleLogWin->Click += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::btnToggleLogWin_Click);
      // 
      // lblSPTVersion
      // 
      this->lblSPTVersion->Location = System::Drawing::Point(94, 17);
      this->lblSPTVersion->Name = L"lblSPTVersion";
      this->lblSPTVersion->Size = System::Drawing::Size(110, 14);
      this->lblSPTVersion->TabIndex = 26;
      // 
      // lblSPTVersionTitle
      // 
      this->lblSPTVersionTitle->AutoSize = true;
      this->lblSPTVersionTitle->Location = System::Drawing::Point(23, 17);
      this->lblSPTVersionTitle->Name = L"lblSPTVersionTitle";
      this->lblSPTVersionTitle->Size = System::Drawing::Size(69, 14);
      this->lblSPTVersionTitle->TabIndex = 25;
      this->lblSPTVersionTitle->Text = L"SPT-Version:";
      // 
      // memoResults
      // 
      this->memoResults->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
        | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->memoResults->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->memoResults->Location = System::Drawing::Point(24, 554);
      this->memoResults->Multiline = true;
      this->memoResults->Name = L"memoResults";
      this->memoResults->ReadOnly = true;
      this->memoResults->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
      this->memoResults->Size = System::Drawing::Size(423, 193);
      this->memoResults->TabIndex = 27;
      // 
      // tmrStatusPoll
      // 
      this->tmrStatusPoll->Interval = 300;
      this->tmrStatusPoll->Tick += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::tmrStatusPoll_Tick);
      // 
      // btnClear
      // 
      this->btnClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->btnClear->Font = (gcnew System::Drawing::Font(L"Arial", 8));
      this->btnClear->Location = System::Drawing::Point(406, 534);
      this->btnClear->Name = L"btnClear";
      this->btnClear->Size = System::Drawing::Size(41, 20);
      this->btnClear->TabIndex = 30;
      this->btnClear->Text = L"Clear";
      this->btnClear->TextAlign = System::Drawing::ContentAlignment::TopCenter;
      this->btnClear->UseVisualStyleBackColor = true;
      this->btnClear->Click += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::btnClear_Click);
      // 
      // grpMeasurement
      // 
      this->grpMeasurement->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->grpMeasurement->Controls->Add(this->cbxStopReason);
      this->grpMeasurement->Controls->Add(this->lblNACKRec);
      this->grpMeasurement->Controls->Add(this->sedtNACKRecords);
      this->grpMeasurement->Controls->Add(this->chkFeedbackConditionedStop);
      this->grpMeasurement->Controls->Add(this->chkRestart);
      this->grpMeasurement->Controls->Add(this->btnStopMeas);
      this->grpMeasurement->Controls->Add(this->sedtAutoStopTime);
      this->grpMeasurement->Controls->Add(this->lblSeconds);
      this->grpMeasurement->Controls->Add(this->chkAutoStop);
      this->grpMeasurement->Controls->Add(this->btnStartMeas);
      this->grpMeasurement->Location = System::Drawing::Point(24, 448);
      this->grpMeasurement->Name = L"grpMeasurement";
      this->grpMeasurement->Size = System::Drawing::Size(423, 85);
      this->grpMeasurement->TabIndex = 31;
      this->grpMeasurement->TabStop = false;
      this->grpMeasurement->Text = L"   Measurement   ";
      // 
      // cbxStopReason
      // 
      this->cbxStopReason->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
      this->cbxStopReason->Font = (gcnew System::Drawing::Font(L"Courier New", 8));
      this->cbxStopReason->FormattingEnabled = true;
      this->cbxStopReason->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"finished", L"user brk.", L"error"});
      this->cbxStopReason->Location = System::Drawing::Point(269, 59);
      this->cbxStopReason->MaxDropDownItems = 3;
      this->cbxStopReason->Name = L"cbxStopReason";
      this->cbxStopReason->Size = System::Drawing::Size(83, 22);
      this->cbxStopReason->TabIndex = 38;
      // 
      // lblNACKRec
      // 
      this->lblNACKRec->Location = System::Drawing::Point(241, 62);
      this->lblNACKRec->Name = L"lblNACKRec";
      this->lblNACKRec->Size = System::Drawing::Size(28, 15);
      this->lblNACKRec->TabIndex = 37;
      this->lblNACKRec->Text = L"with";
      this->lblNACKRec->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
      // 
      // sedtNACKRecords
      // 
      this->sedtNACKRecords->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->sedtNACKRecords->Location = System::Drawing::Point(199, 59);
      this->sedtNACKRecords->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {99, 0, 0, 0});
      this->sedtNACKRecords->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
      this->sedtNACKRecords->Name = L"sedtNACKRecords";
      this->sedtNACKRecords->Size = System::Drawing::Size(44, 20);
      this->sedtNACKRecords->TabIndex = 36;
      this->sedtNACKRecords->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
      this->sedtNACKRecords->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
      // 
      // chkFeedbackConditionedStop
      // 
      this->chkFeedbackConditionedStop->Font = (gcnew System::Drawing::Font(L"Arial", 8));
      this->chkFeedbackConditionedStop->Location = System::Drawing::Point(67, 61);
      this->chkFeedbackConditionedStop->Margin = System::Windows::Forms::Padding(0);
      this->chkFeedbackConditionedStop->Name = L"chkFeedbackConditionedStop";
      this->chkFeedbackConditionedStop->Size = System::Drawing::Size(132, 16);
      this->chkFeedbackConditionedStop->TabIndex = 35;
      this->chkFeedbackConditionedStop->Text = L"Stop on Feedback No.";
      this->chkFeedbackConditionedStop->TextAlign = System::Drawing::ContentAlignment::TopLeft;
      this->chkFeedbackConditionedStop->UseVisualStyleBackColor = true;
      this->chkFeedbackConditionedStop->CheckedChanged += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::chkFeedbackConditionedStop_CheckedChanged);
      // 
      // chkRestart
      // 
      this->chkRestart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->chkRestart->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
      this->chkRestart->Enabled = false;
      this->chkRestart->Font = (gcnew System::Drawing::Font(L"Arial", 8));
      this->chkRestart->Location = System::Drawing::Point(352, 30);
      this->chkRestart->Margin = System::Windows::Forms::Padding(0);
      this->chkRestart->Name = L"chkRestart";
      this->chkRestart->Size = System::Drawing::Size(64, 46);
      this->chkRestart->TabIndex = 34;
      this->chkRestart->Text = L"Restart after Stop";
      this->chkRestart->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
      this->chkRestart->UseVisualStyleBackColor = true;
      // 
      // btnStopMeas
      // 
      this->btnStopMeas->Enabled = false;
      this->btnStopMeas->Location = System::Drawing::Point(67, 17);
      this->btnStopMeas->Name = L"btnStopMeas";
      this->btnStopMeas->Size = System::Drawing::Size(285, 23);
      this->btnStopMeas->TabIndex = 30;
      this->btnStopMeas->Text = L"    &Stop manually";
      this->btnStopMeas->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
      this->btnStopMeas->UseVisualStyleBackColor = true;
      this->btnStopMeas->Click += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::btnStopMeas_Click);
      // 
      // sedtAutoStopTime
      // 
      this->sedtAutoStopTime->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->sedtAutoStopTime->Location = System::Drawing::Point(146, 41);
      this->sedtAutoStopTime->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {99, 0, 0, 0});
      this->sedtAutoStopTime->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
      this->sedtAutoStopTime->Name = L"sedtAutoStopTime";
      this->sedtAutoStopTime->Size = System::Drawing::Size(44, 20);
      this->sedtAutoStopTime->TabIndex = 32;
      this->sedtAutoStopTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
      this->sedtAutoStopTime->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {7, 0, 0, 0});
      // 
      // lblSeconds
      // 
      this->lblSeconds->Location = System::Drawing::Point(190, 45);
      this->lblSeconds->Name = L"lblSeconds";
      this->lblSeconds->Size = System::Drawing::Size(25, 14);
      this->lblSeconds->TabIndex = 33;
      this->lblSeconds->Text = L"sec";
      this->lblSeconds->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
      // 
      // chkAutoStop
      // 
      this->chkAutoStop->Font = (gcnew System::Drawing::Font(L"Arial", 8));
      this->chkAutoStop->Location = System::Drawing::Point(67, 44);
      this->chkAutoStop->Margin = System::Windows::Forms::Padding(0);
      this->chkAutoStop->Name = L"chkAutoStop";
      this->chkAutoStop->Size = System::Drawing::Size(74, 17);
      this->chkAutoStop->TabIndex = 31;
      this->chkAutoStop->Text = L"Stop after";
      this->chkAutoStop->TextAlign = System::Drawing::ContentAlignment::TopLeft;
      this->chkAutoStop->UseVisualStyleBackColor = true;
      this->chkAutoStop->CheckedChanged += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::chkAutoStop_CheckedChanged);
      // 
      // btnStartMeas
      // 
      this->btnStartMeas->Enabled = false;
      this->btnStartMeas->Location = System::Drawing::Point(17, 17);
      this->btnStartMeas->Name = L"btnStartMeas";
      this->btnStartMeas->Size = System::Drawing::Size(47, 63);
      this->btnStartMeas->TabIndex = 29;
      this->btnStartMeas->Text = L"&Run";
      this->btnStartMeas->UseVisualStyleBackColor = true;
      this->btnStartMeas->Click += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::btnStartMeas_Click);
      // 
      // lblProtocoll
      // 
      this->lblProtocoll->AutoSize = true;
      this->lblProtocoll->Location = System::Drawing::Point(23, 538);
      this->lblProtocoll->Name = L"lblProtocoll";
      this->lblProtocoll->Size = System::Drawing::Size(58, 14);
      this->lblProtocoll->TabIndex = 32;
      this->lblProtocoll->Text = L"Audit Trail:";
      // 
      // tmrAutoStop
      // 
      this->tmrAutoStop->Interval = 1000;
      this->tmrAutoStop->Tick += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::tmrAutoStop_Tick);
      // 
      // tmrSynchronize
      // 
      this->tmrSynchronize->Interval = 150;
      this->tmrSynchronize->Tick += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::tmrSynchronize_Tick);
      // 
      // Client_LSM_SymPhoTime_Dlg
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 14);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(468, 764);
      this->Controls->Add(this->lblProtocoll);
      this->Controls->Add(this->grpMeasurement);
      this->Controls->Add(this->btnClear);
      this->Controls->Add(this->memoResults);
      this->Controls->Add(this->lblSPTVersion);
      this->Controls->Add(this->lblSPTVersionTitle);
      this->Controls->Add(this->btnToggleLogWin);
      this->Controls->Add(this->lblDLLVersion);
      this->Controls->Add(this->lblDLLVersionTitle);
      this->Controls->Add(this->lblVersion);
      this->Controls->Add(this->grpConnection);
      this->Controls->Add(this->grpImgOptional);
      this->Controls->Add(this->grpMandatory);
      this->Controls->Add(this->grpOptional);
      this->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(0)));
      this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
      this->MaximizeBox = false;
      this->MinimumSize = System::Drawing::Size(470, 660);
      this->Name = L"Client_LSM_SymPhoTime_Dlg";
      this->Text = L"   Stress - Application  (simul. LSM - Client  →  SymPhoTime)";
      this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Client_LSM_SymPhoTime_Dlg::Client_LSM_SymPhoTime_Dlg_FormClosed);
      this->Load += gcnew System::EventHandler(this, &Client_LSM_SymPhoTime_Dlg::Client_LSM_SymPhoTime_Dlg_Load);
      this->grpMandatory->ResumeLayout(false);
      this->grpMandatory->PerformLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtPixX))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtResol))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtPixY))->EndInit();
      this->pnlScanDirection->ResumeLayout(false);
      this->pnlScanDirection->PerformLayout();
      this->grpImgOptional->ResumeLayout(false);
      this->grpImgOptional->PerformLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtTimePerImage))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtTimePerPixel))->EndInit();
      this->grpOptional->ResumeLayout(false);
      this->grpOptional->PerformLayout();
      this->grpConnection->ResumeLayout(false);
      this->grpConnection->PerformLayout();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtPort))->EndInit();
      this->grpMeasurement->ResumeLayout(false);
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtNACKRecords))->EndInit();
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sedtAutoStopTime))->EndInit();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
private: System::Void chkSquare_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
            if (!this->bLoaded) return;
            if (this->chkSquare->Checked)
            {
              this->sedtPixY->Enabled = false;
              this->sedtPixY->Value = this->sedtPixX->Value;
            }
            else
            {
              this->sedtPixY->Enabled = true;
            }
          }
private: System::Void sedtPixX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
           if (!this->bLoaded) return;
           if (this->chkSquare->Checked)
           {
             this->sedtPixY->Value = this->sedtPixX->Value;
           }
         }
private: System::Void rbtnImageScan_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
           bool bImage = this->rbtnImageScan->Checked;
           //
           if (!this->bLoaded) return;
           this->cbxResolUnit->Enabled = bImage;
           this->sedtResol->Enabled = bImage;
           this->chkSquare->Enabled = bImage;
           this->sedtPixY->Enabled = bImage && !this->chkSquare->Checked;
           this->sedtPixX->Enabled = bImage;
           this->rbtnBiDirectional->Enabled = bImage;
           this->rbtnMonoDirectional->Enabled = bImage;
           this->chkTimePerPixel->Enabled = bImage;
           this->cbxTimePerPixelUnit->Enabled = bImage;
           this->sedtTimePerPixel->Enabled = bImage;
           this->chkTimePerImage->Enabled = bImage;
           this->cbxTimePerImageUnit->Enabled = bImage;
           this->sedtTimePerImage->Enabled = bImage;
         }
private: System::Void Client_LSM_SymPhoTime_Dlg_Load(System::Object^  sender, System::EventArgs^  e) {
           long             lRet;
           char             cVersion     [SPT_RI_VERSIONSTRING_MAXLEN + 1];
           char             cStatus      [SPT_RI_STATUSTEXT_MAXLEN    + 1];
           const char*      pcLogFileName;
           marshal_context^ context      = gcnew marshal_context();
           //
           this->bLoaded = false;
           //
           ParamCBFunc = MyParamCBFunc;

           if (PQ_ERRCODE_NO_ERROR != (lRet = InitRemoteInterface_DLL ()))
           {
             switch (lRet)
             {
               case PQ_ERRCODE_DLL_NOT_FOUND:
                 MessageBox::Show (L"Remote interface DLL not found!", L"Stress - Application", MessageBoxButtons::OK, MessageBoxIcon::Error);
                 Close();
               break;
               case PQ_ERRCODE_UNKNOWN_FUNCTION:
                 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
                 if (System::Windows::Forms::DialogResult::Yes != MessageBox::Show (L"Function(s) missing in remote interface DLL!\nDo you want to start the program anyway?", L"Stress - Application", buttons, MessageBoxIcon::Warning))
                 {
                   Close();
                 }
               break;
             }
           }
           //
           while (PQ_ERRCODE_CLIENT_NOT_INITIALISED == (lRet = RI_GetLibVersion (cVersion)))
           {
             Sleep (100);
           }
           if (PQ_ERRCODE_NO_ERROR == lRet)
           {
             this->lblDLLVersion->Text = marshal_as<String^> (cVersion);
           }
           else
           {
             this->lblDLLVersion->Text = L"???";
           }
           //
           RI_GetStatusText (SPT_RI_STATUS_UNKNOWN, cStatus);
           this->strSPT_RI_STATUS_UNKNOWN = marshal_as<String^> (cStatus);
           RI_GetStatusText (SPT_RI_STATUS_IDLE, cStatus);
           this->strSPT_RI_STATUS_IDLE = marshal_as<String^> (cStatus);
           RI_GetStatusText (SPT_RI_STATUS_MEAS_RUNNING, cStatus);
           this->strSPT_RI_STATUS_MEAS_RUNNING = marshal_as<String^> (cStatus);
           RI_GetStatusText (SPT_RI_STATUS_MEAS_TERMINATING, cStatus);
           this->strSPT_RI_STATUS_MEAS_TERMINATING = marshal_as<String^> (cStatus); 
           //
           if (0 < this->strLogFileName->Length)
           {
             pcLogFileName = context->marshal_as <const char*> (this->strLogFileName);
             if (PQ_ERRCODE_NO_ERROR != (lRet = RI_AssignLogFile ((char*)pcLogFileName)))
             {
               MessageBox::Show (L"Could not assign logfile '" + this->strLogFileName + L"'!", L"Stress - Application", MessageBoxButtons::OK, MessageBoxIcon::Error);
             }
           }
           //
           if (PQ_ERRCODE_NO_ERROR == (lRet = RI_GetStatusText (RI_GetStatus (), cStatus)))
           {
             this->edtState->Text = marshal_as<String^> (cStatus);
           }
           else
           {
             this->edtState->Text = L"???";
           }
           //
           this->iLastNonLocalIP = (192 << 24) + (168 << 16) + (43 << 8) + 3;
           this->cbxResolUnit->SelectedIndex = 1;
           this->cbxTimePerPixelUnit->SelectedIndex = 1;
           this->cbxTimePerImageUnit->SelectedIndex = 1;
           this->cbxStopReason->SelectedIndex = 1;
           //
           this->bLoaded = true;
           delete context;
         }
private protected: System::Void rbtnLocal_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
           bool bLocal = this->rbtnLocal->Checked;
           //
         //if (!this->bLoaded) return;
           if (bLocal) {
             iLastNonLocalIP = (Byte::Parse (this->edtIPAdrFld1->Text) << 24) +
                               (Byte::Parse (this->edtIPAdrFld2->Text) << 16) +
                               (Byte::Parse (this->edtIPAdrFld3->Text) <<  8) +
                                Byte::Parse (this->edtIPAdrFld4->Text);
             //
             this->lblIPAdress->Text  = "127.0.0.1";
           }
           else
           {
             this->edtIPAdrFld1->Text = ((long)((iLastNonLocalIP & 0xFF000000) >> 24)).ToString();
             this->edtIPAdrFld2->Text = ((long)((iLastNonLocalIP & 0x00FF0000) >> 16)).ToString();
             this->edtIPAdrFld3->Text = ((long)((iLastNonLocalIP & 0x0000FF00) >>  8)).ToString();
             this->edtIPAdrFld4->Text = ((long) (iLastNonLocalIP & 0x000000FF)       ).ToString();
             //
             this->lblIPAdress->Text  = this->edtIPAdrFld1->Text + "." + 
                                        this->edtIPAdrFld2->Text + "." + 
                                        this->edtIPAdrFld3->Text + "." + 
                                        this->edtIPAdrFld4->Text;
           }
           this->edtIPAdrFld1->Enabled = ! bLocal;
           this->edtIPAdrFld2->Enabled = ! bLocal;
           this->edtIPAdrFld3->Enabled = ! bLocal;
           this->edtIPAdrFld4->Enabled = ! bLocal;
         }
private: System::Void edtIPAdrFld_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
           if (bIPAdressKeyNotAllowed) {
             e->Handled = true;
           }
         }
private: System::Void edtIPAdrFld_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
           bIPAdressKeyNotAllowed = false;
           //If shift key was pressed, it's not a number.
           if (Control::ModifierKeys == Keys::Shift) {
             bIPAdressKeyNotAllowed = true;
           }
           // Determine whether the keystroke is a number from the top of the keyboard.
           if ( e->KeyCode < Keys::D0 || e->KeyCode > Keys::D9 )
           {
             // Determine whether the keystroke is a number from the keypad.
             if ( e->KeyCode < Keys::NumPad0 || e->KeyCode > Keys::NumPad9 )
             {
               // Determine whether the keystroke is a backspace.
               if (! ( ( e->KeyCode == Keys::Back ) 
                    || ( e->KeyCode == Keys::Delete )
                    || ( e->KeyCode == Keys::Tab )
                    || ( e->KeyCode == Keys::Left )
                    || ( e->KeyCode == Keys::Right )
                     )
                  )
               {
                 // A non-numerical keystroke was pressed.
                 // Set the flag to true and evaluate in KeyPress event.
                 bIPAdressKeyNotAllowed = true;
               }
             }
           }
         }
private: System::Void edtIPAdrFld_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
           //
           System::Windows::Forms::TextBox^ sndr = (System::Windows::Forms::TextBox^)sender;
           String^ s = sndr->Text;
           int i;
           //
           if (!bIPAdressKeyNotAllowed) {
             sndr->Text = s->TrimStart ('0');
             if (sndr->Text == "")
             {
               sndr->Text = "0";
             }
             if (s != sndr->Text) {
               sndr->SelectionStart = 1;
             }
             if (255 < (i = Int16::Parse (sndr->Text)))
             {
               sndr->Text = "255";
               sndr->SelectionStart = 1;
             }
             if (3 == sndr->Text->Length)
             {
               sndr->SelectionLength = 1;
             }
           }
         }
private: System::Void edtIPAdrFld_Leave(System::Object^  sender, System::EventArgs^  e) {
           this->lblIPAdress->Text = this->edtIPAdrFld1->Text + "." + 
                                     this->edtIPAdrFld2->Text + "." + 
                                     this->edtIPAdrFld3->Text + "." + 
                                     this->edtIPAdrFld4->Text;
         }
private: System::Void btnInitConnection_Click(System::Object^  sender, System::EventArgs^  e) {
           // Init Button
           long  lRet;
           char  cHostName   [SPT_RI_HOSTNAME_MAXLEN+1];
           char  cSPTVersion [SPT_RI_VERSIONSTRING_MAXLEN+1];
           char  cStatus [SPT_RI_STATUSTEXT_MAXLEN+1];
           char  cErrText [SPT_RI_ERRORTEXT_MAXLEN+1];
           long  iPort;
           const char* pcTemp;
           marshal_context^ context = gcnew marshal_context();
           //
           pcTemp = context->marshal_as <const char*> (this->lblIPAdress->Text);
           strcpy_s (cHostName, SPT_RI_HOSTNAME_MAXLEN, pcTemp);
           //
           pcTemp = context->marshal_as <const char*> (this->sedtPort->Text);
           iPort = atoi (pcTemp);
           //
           _strset_s (cSPTVersion, SPT_RI_VERSIONSTRING_MAXLEN+1, 0);
           //
           if (PQ_ERRCODE_NO_ERROR == (lRet = RI_Initialize (cHostName, iPort, cSPTVersion)))
           {
             if (PQ_ERRCODE_NO_ERROR == (lRet = RI_GetStatusText (RI_GetStatus (), cStatus)))
             {
               this->edtState->Text = marshal_as<String^> (cStatus);
             }
             else
             {
               this->edtState->Text = L"???";
             }
             //
             if (0  < strlen(cSPTVersion))
             {
               this->lblSPTVersion->Text = marshal_as<String^> (cSPTVersion);
             }
             else
             {
               this->lblSPTVersion->Text = "???";
             }
           }
           //
           RI_GetErrorText (lRet, cErrText);
           memoResults->AppendText (Environment::NewLine +  L"RI_Initialize : \"" + marshal_as<String^> (cErrText) + L"\"");
           //
           delete context;
         }
private: System::Void btnToggleLogWin_Click(System::Object^  sender, System::EventArgs^  e) {
           long lRet;
           char  cErrText [SPT_RI_ERRORTEXT_MAXLEN+1];
           //
           if (this->btnToggleLogWin->Tag == L"0")
           {
             if (PQ_ERRCODE_NO_ERROR == (lRet = RI_ShowLogWin ()))
             {
               this->btnToggleLogWin->Tag  = L"1";
               this->btnToggleLogWin->Text = "Hide &Log-Window";
             }
             //  
             RI_GetErrorText (lRet, cErrText);
             memoResults->AppendText (Environment::NewLine +  L"RI_ShowLogWin : \"" + marshal_as<String^> (cErrText) + L"\"");
           }
           else
           {
             if (PQ_ERRCODE_NO_ERROR == (lRet = RI_HideLogWin ()))
             {
               this->btnToggleLogWin->Tag = L"0";
               this->btnToggleLogWin->Text = "Show &Log-Window";
             }
             //  
             RI_GetErrorText (lRet, cErrText);
             memoResults->AppendText (Environment::NewLine +  L"RI_HideLogWin : \"" + marshal_as<String^> (cErrText) + L"\"");
           }
         }
private: System::Void Client_LSM_SymPhoTime_Dlg_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
           if (hDLL != NULL) 
           { 
             // Free the DLL module.
             FreeLibrary(hDLL); 
           } 
         }
private: System::Void edtState_TextChanged(System::Object^  sender, System::EventArgs^  e) {
           bool  bUndefinedState; 
           bool  bIdleState; 
           bool  bMeasState; 
           //
           if (!this->bLoaded) return;
           //
           this->memoResults->AppendText (Environment::NewLine + L"Status changed to " + this->edtState->Text);
           //
           bUndefinedState = ((this->edtState->Text == strSPT_RI_STATUS_UNKNOWN) || (this->edtState->Text == L"???")); 
           bIdleState      = (this->edtState->Text == strSPT_RI_STATUS_IDLE);
           bMeasState      = !(bUndefinedState || bIdleState);
           //
           if (bUndefinedState)
           {
             this->tmrStatusPoll->Enabled     = false;
             this->btnStartMeas->Enabled      = false;
             this->btnStopMeas->Enabled       = false;
             this->btnInitConnection->Enabled = true;
             //
             this->tmrSynchronize->Enabled    = false;
           }
           else
           {
             if (bIdleState)
             {
               this->tmrStatusPoll->Interval    = 750;
               this->btnStartMeas->Enabled      = true;
               this->btnStopMeas->Enabled       = false;
               this->btnInitConnection->Enabled = true;
               //
               this->tmrSynchronize->Enabled    = false;
               //
               if (this->iStopFired == STOP_FIRED_BY_FEEDBACK)
               {
                 this->tmrAutoStop->Enabled     = false;
                 this->btnStopMeas_Click (sender, e);
               }
             }
             else
             {
               this->tmrStatusPoll->Interval    = 330;
               this->btnStartMeas->Enabled      = false;
               this->btnStopMeas->Enabled       = true;
               this->btnInitConnection->Enabled = false;
             }
             this->tmrStatusPoll->Enabled = true;
           }
           //
         }
private: System::Void btnStartMeas_Click(System::Object^  sender, System::EventArgs^  e) {
           const char* pcTemp;
           char  cErrText    [SPT_RI_ERRORTEXT_MAXLEN + 1];
           char  cFileName   [SPT_RI_FILENAME_MAXLEN  + 1];
           char  cGroupName  [SPT_RI_GROUPNAME_MAXLEN + 1];
           char  cComment    [SPT_RI_COMMENT_MAXLEN   + 1];
           char  cFloatParam [50];
           int   iTrys = 0;
           long  lRet;
           long  iPixX;
           long  iPixY;
           float fTimePix;
           float fTimeImg;
           float fResol;
           //
           marshal_context^ context = gcnew marshal_context();
           bool             bImage  = this->rbtnImageScan->Checked;
           bool             bRecord = !(this->chkTestMeas->Checked);
           //
           this->iStopFired = STOP_FIRED_BY_USER;
           //
           // Compile optional parameters
           if (bImage)
           {
             pcTemp = context->marshal_as <const char*> (this->sedtTimePerPixel->Text);
             fTimePix = 1.0f * atoi (pcTemp);
             for (int i=0; i <= this->cbxTimePerPixelUnit->SelectedIndex; i++)
             {
               fTimePix *= 1.0e-3f;
             }
             //
             if (this->chkTimePerPixel->Checked)
             {
               lRet = RI_SetOptionalFloat (PQ_OPT_INFONAME_TIME_PER_PIXEL, fTimePix, -1);
               sprintf_s (cFloatParam, 14, "%12.3e", fTimePix);
               //
               RI_GetErrorText (lRet, cErrText);
               memoResults->AppendText (Environment::NewLine +  L"RI_SetOptionalFloat : \"" + marshal_as<String^> (cErrText) + L"\"" + Environment::NewLine +  L"   (" + PQ_OPT_INFONAME_TIME_PER_PIXEL + L" = " +  marshal_as<String^> (cFloatParam) + L")");
             }
             if (this->chkTimePerImage->Checked)
             {
               pcTemp = context->marshal_as <const char*> (this->sedtTimePerImage->Text);
               fTimeImg = 1.0f * atoi (pcTemp);
               for (int i=1; i <= this->cbxTimePerImageUnit->SelectedIndex; i++)
               {
                 fTimeImg *= 1.0e-3f;
               }
               lRet = RI_SetOptionalFloat (PQ_OPT_INFONAME_TIME_PER_IMAGE, fTimeImg, -1);
               sprintf_s (cFloatParam, 14, "%12.3e", fTimeImg);
               //
               RI_GetErrorText (lRet, cErrText);
               memoResults->AppendText (Environment::NewLine +  L"RI_SetOptionalFloat : \"" + marshal_as<String^> (cErrText) + L"\"" + Environment::NewLine +  L"   (" + PQ_OPT_INFONAME_TIME_PER_IMAGE + L" = " +  marshal_as<String^> (cFloatParam) + L")");
             }
           }
           if (this->chkFilename->Checked)
           {
             pcTemp = context->marshal_as <const char*> (this->edtFilename->Text);
             strcpy_s (cFileName, SPT_RI_FILENAME_MAXLEN, pcTemp);
             lRet = RI_SetOptionalString (PQ_OPT_INFONAME_FILENAME, cFileName);
             //
             RI_GetErrorText (lRet, cErrText);
             memoResults->AppendText (Environment::NewLine +  L"RI_SetOptionalString : \"" + marshal_as<String^> (cErrText) + L"\"" + Environment::NewLine +  L"   (" + PQ_OPT_INFONAME_FILENAME + L" = " +  marshal_as<String^> (cFileName) + L")");
           }
           if (this->chkGroupname->Checked)
           {
             pcTemp = context->marshal_as <const char*> (this->edtGroupname->Text);
             strcpy_s (cGroupName, SPT_RI_GROUPNAME_MAXLEN, pcTemp);
             lRet = RI_SetOptionalString (PQ_OPT_INFONAME_GROUPNAME, cGroupName);
             //
             RI_GetErrorText (lRet, cErrText);
             memoResults->AppendText (Environment::NewLine +  L"RI_SetOptionalString : \"" + marshal_as<String^> (cErrText) + L"\"" + Environment::NewLine +  L"   (" + PQ_OPT_INFONAME_GROUPNAME + L" = " +  marshal_as<String^> (cGroupName) + L")");
           }
           if (this->chkComment->Checked)
           {
             pcTemp = context->marshal_as <const char*> (this->edtComment->Text);
             strcpy_s (cComment, SPT_RI_COMMENT_MAXLEN, pcTemp);
             lRet = RI_SetOptionalString (PQ_OPT_INFONAME_COMMENT, cComment);
             //
             RI_GetErrorText (lRet, cErrText);
             memoResults->AppendText (Environment::NewLine +  L"RI_SetOptionalString : \"" + marshal_as<String^> (cErrText) + L"\"" + Environment::NewLine +  L"   (" + PQ_OPT_INFONAME_COMMENT + L" = " +  marshal_as<String^> (cComment) + L")");
           }
           //
           // Invoke measurement request function
           if (bImage)
           {
             pcTemp = context->marshal_as <const char*> (this->sedtPixX->Text);
             iPixX = atoi (pcTemp);
             pcTemp = context->marshal_as <const char*> (this->sedtPixY->Text);
             iPixY = atoi (pcTemp);
             pcTemp = context->marshal_as <const char*> (this->sedtResol->Text);
             fResol = 1.0f * atoi (pcTemp);
             for (int i=0; i <= this->cbxResolUnit->SelectedIndex; i++)
             {
               fResol *= 1.0e-3f;
             }
             // (longbool bRecordFile, long iPixX, long iPixY, float fResol, longbool bBiDirectionalScan, TReceiveParamFunc ParamCallbackFunc);
             lRet = RI_RequestImage (bRecord, iPixX, iPixY, fResol, this->rbtnBiDirectional->Checked, this->ParamCBFunc);
             //
             RI_GetErrorText (lRet, cErrText);
             memoResults->AppendText (Environment::NewLine +  L"RI_RequestImage : \"" + marshal_as<String^> (cErrText) + L"\"");
           }
           else
           {
             lRet = RI_RequestTimeTrace (bRecord, this->ParamCBFunc);
             //
             RI_GetErrorText (lRet, cErrText);
             memoResults->AppendText (Environment::NewLine +  L"RI_RequestTimeTrace : \"" + marshal_as<String^> (cErrText) + L"\"");
           }
           if ( (lRet == PQ_ERRCODE_NO_ERROR) && this->chkAutoStop->Checked)
           {
             char cDebugOutStr [64];
             //
             pcTemp = context->marshal_as <const char*> (this->sedtAutoStopTime->Text);
             this->tmrAutoStop->Interval = 1000 * atoi (pcTemp);
             sprintf_s (cDebugOutStr, 63, "Client launches Stop Timer : %d msec", this->tmrAutoStop->Interval);
             memoResults->AppendText (Environment::NewLine + marshal_as<String^> (cDebugOutStr));
             RI_AddLineToLog (cDebugOutStr);
             this->tmrAutoStop->Enabled  = true;
           }
           delete context;
           //
           this->tmrSynchronize->Enabled = (lRet == PQ_ERRCODE_NO_ERROR);
           this->tmrStatusPoll->Enabled  = true;
         }
private: System::Void btnStopMeas_Click(System::Object^  sender, System::EventArgs^  e) {
           char cErrText [SPT_RI_ERRORTEXT_MAXLEN+1];
           //
           this->tmrAutoStop->Enabled    = false;
           this->tmrSynchronize->Enabled = false;
           this->tmrSynchronize_Tick (sender, e);
           //
           //
           switch (this->iStopFired)
           {
             case STOP_FIRED_BY_USER : 
               memoResults->AppendText (Environment::NewLine +  L"Measurement stopped by user");
               RI_AddLineToLog ("Measurement stopped by user");
             break;
             case STOP_FIRED_BY_FEEDBACK : 
               memoResults->AppendText (Environment::NewLine +  L"Measurement stopped by feedback");
               RI_AddLineToLog ("Measurement stopped by feedback");
             break;
             case STOP_FIRED_BY_TIMER : 
               memoResults->AppendText (Environment::NewLine +  L"Measurement stopped by timer");
               RI_AddLineToLog ("Measurement stopped by timer");
             break;
           }
           //
           if (this->iStopFired == STOP_FIRED_BY_FEEDBACK)
           {
             Sleep(600);
           }
           else
           {
             long lRet = RI_RequestStopMeas ();
             //
             RI_GetErrorText (lRet, cErrText);
             memoResults->AppendText (Environment::NewLine +  L"RI_RequestStopMeas : \"" + marshal_as<String^> (cErrText) + L"\"");
           }
           //
           this->tmrStatusPoll_Tick (sender, e);
           //
           if (this->chkRestart->Checked && this->btnStartMeas->Enabled)
           {
             this->btnStartMeas_Click (sender, e);
           }
         }
private: System::Void tmrStatusPoll_Tick(System::Object^  sender, System::EventArgs^  e) {
           long lRet;
           char cStatus  [SPT_RI_STATUSTEXT_MAXLEN+1];
           //
           this->tmrStatusPoll->Enabled = false;
           //
           if (PQ_ERRCODE_NO_ERROR == (lRet = RI_GetStatusText (RI_GetStatus (), cStatus)))
           {
             if (this->edtState->Text != marshal_as<String^> (cStatus))
             {
               this->edtState->Text = marshal_as<String^> (cStatus);
             }
           }
           else
           {
             this->edtState->Text = L"???";
           }
           this->tmrStatusPoll->Enabled = true;
         }
private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) {
           this->memoResults->Clear();
         }

private: System::Void tmrAutoStop_Tick(System::Object^  sender, System::EventArgs^  e) {
           char cDebugOutStr [64];
           //
           this->tmrAutoStop->Enabled = false;
           //
           sprintf_s (cDebugOutStr, 63, "---------------> Stop Timer fired after %d msec!", this->tmrAutoStop->Interval);
           memoResults->AppendText (Environment::NewLine + marshal_as<String^> (cDebugOutStr));
           RI_AddLineToLog (cDebugOutStr);
           //
           if (this->btnStopMeas->Enabled)
           {
             this->iStopFired = STOP_FIRED_BY_TIMER;
             //
             strcpy_s (cDebugOutStr, 63, "---------------> Simulating click on Stop button!");
             memoResults->AppendText (Environment::NewLine + marshal_as<String^> (cDebugOutStr));
             RI_AddLineToLog (cDebugOutStr);
             //
             this->btnStopMeas_Click (sender, e);
           }
           else
           {
             //
             strcpy_s (cDebugOutStr, 63, "---------------> Stop button was already disabled!");
             memoResults->AppendText (Environment::NewLine + marshal_as<String^> (cDebugOutStr));
             RI_AddLineToLog (cDebugOutStr);
             //
           }
         }
private: System::Void chkAutoStop_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
           this->chkRestart->Enabled = (this->chkAutoStop->Checked || this->chkFeedbackConditionedStop->Checked);
           if (!this->chkRestart->Enabled)
           {
             this->chkRestart->Checked = false;
           }
         }
private: System::Void chkFeedbackConditionedStop_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
           this->chkRestart->Enabled = (this->chkAutoStop->Checked || this->chkFeedbackConditionedStop->Checked);
           if (!this->chkRestart->Enabled)
           {
             this->chkRestart->Checked = false;
           }
         }
private: System::Void tmrSynchronize_Tick(System::Object^  sender, System::EventArgs^  e) {
           bool bWasEnabled = this->tmrSynchronize->Enabled;
           //
           this->tmrSynchronize->Enabled = false;
           //
           if (this->bSyncServerVersion)
           {
             this->lblSPTVersion->Text = this->strServerVersion;
             //
             this->bSyncServerVersion = false;
           }
           //
           if (this->bSyncResultMemo)
           {
             this->memoResults->AppendText (strResultMemo);
             this->memoResults->SelectionStart = this->memoResults->Text->Length + 1;
             //
             this->bSyncResultMemo = false;
           }
           //
           this->tmrSynchronize->Enabled = bWasEnabled;
         }
};

  Client_LSM_SymPhoTime_Dlg^ *PClient_Dlg;

  long __stdcall MyParamCBFunc (char* pcIdent, float fValue, long iRecNr) {
           char             cParamOutStr [0x100FF];
           String ^         s;
           long             lRet;
           long             lTemp;
           const char*      pcTemp;
           marshal_context^ context      = gcnew marshal_context();
           //
           if (L"ServerVersion" == marshal_as<String^> (pcIdent))
           {
             char cVersionOutStr [30];
             T_OPT_DATA od;
             od.f  = fValue;
             if ((od.v.bMajHi > 4) || ((od.v.bMajHi == 4) && (od.v.bMajLo >= 3)))
             {
               sprintf_s (cVersionOutStr, 29, "%hu.%hu.%hu.%hu", od.v.bMajHi, od.v.bMajLo, od.v.bMinHi, od.v.bMinLo);
             }
             else
             {
               sprintf_s (cVersionOutStr, 29, "%hu.%hu.%hu", od.v.bMajHi, od.v.bMajLo, (od.v.bMinHi << 8) + od.v.bMinLo);
             }
             sprintf_s (cParamOutStr, 99, "%3.3d: %-31s =   V%s", iRecNr, pcIdent, cVersionOutStr);
             if (iRecNr == 1)
             {
               // what we want to do is simply this:
               //
               //(*Client_w_Stress::PClient_Dlg)->lblSPTVersion->Text = marshal_as<String^> (cVersionOutStr);
               //
               // But this style it is not threaddsave. So we have to do it e.g. like this...
               (*Client_w_Stress::PClient_Dlg)->strServerVersion   = marshal_as<String^> (cVersionOutStr);
               (*Client_w_Stress::PClient_Dlg)->bSyncServerVersion = true;
               // ...and the client dialogue has to refresh his label in his own context.
               // see also:  tmrSynchronize_Tick
             }
           }
           else
           {
             if (0 == strncmp ("cpm", pcIdent, 3))
             {
               // i.e. cpm1 or cpm2; read both as float values
               sprintf_s (cParamOutStr, 99, "%3.3d: %-31s = %14.3f", iRecNr, pcIdent, fValue);
             }
             else
             {
               if ( (0 == strncmp ("cps",    pcIdent, 3))
                 || (0 == strncmp ("det",    pcIdent, 3))
                 || (0 == strcmp  ("maxcpp", pcIdent))
                  )
               {
                 // i.e. cps1, cps2 or det1..det4; read them as unsigned long values
                 sprintf_s (cParamOutStr, 99, "%3.3d: %-31s = %10u", iRecNr, pcIdent, int(abs(fValue)));
               }
               else
               {
                 // all others are unknown; 
                 // we don't want to lose information, so we simply show them as floats... 
                 sprintf_s (cParamOutStr, 99, "%3.3d: %-31s = %14.3f", iRecNr, pcIdent, fValue);
               }
             }
           }
           s = marshal_as<String^> (cParamOutStr);
           //
           // what we want to do is simply this:
           //
           //(*Client_w_Stress::PClient_Dlg)->memoResults->AppendText (Environment::NewLine + s);
           //(*Client_w_Stress::PClient_Dlg)->memoResults->SelectionStart = (*Client_w_Stress::PClient_Dlg)->memoResults->Text->Length + 1;
           //
           // But this style it is not threaddsave. So we have to do it e.g. like this...
           (*Client_w_Stress::PClient_Dlg)->strResultMemo += (Environment::NewLine + s);
           (*Client_w_Stress::PClient_Dlg)->bSyncResultMemo = true;
           // ...and the client dialogue has to refresh his memo in his own context.
           // see also:  tmrSynchronize_Tick
           //
           if ((*Client_w_Stress::PClient_Dlg)->chkFeedbackConditionedStop->Checked)
           {
             pcTemp = context->marshal_as <const char*> ((*Client_w_Stress::PClient_Dlg)->sedtNACKRecords->Text);
             lTemp  = atoi (pcTemp);
             //
             if (lTemp <= iRecNr)
             {
               switch ((*Client_w_Stress::PClient_Dlg)->cbxStopReason->SelectedIndex)
               {
                 case 0: 
                   lRet = SPT_RI_STOP_REASON_FINISHED_OK; 
                   // //(*Client_w_Stress::PClient_Dlg)->memoResults->AppendText (Environment::NewLine + "Callback registers SPT_RI_STOP_REASON_FINISHED_OK");
                   //(*Client_w_Stress::PClient_Dlg)->strResultMemo += (Environment::NewLine + "Callback registers SPT_RI_STOP_REASON_FINISHED_OK");
                   //RI_AddLineToLog ("Callback registers SPT_RI_STOP_REASON_FINISHED_OK");
                 break;
                 case 1: 
                   lRet = SPT_RI_STOP_REASON_USER_BREAK;  
                   // //(*Client_w_Stress::PClient_Dlg)->memoResults->AppendText (Environment::NewLine + "Callback registers SPT_RI_STOP_REASON_USER_BREAK");
                   //(*Client_w_Stress::PClient_Dlg)->strResultMemo += (Environment::NewLine + "Callback registers SPT_RI_STOP_REASON_USER_BREAK");
                   //RI_AddLineToLog ("Callback registers SPT_RI_STOP_REASON_USER_BREAK");
                 break;
                 case 2: 
                   lRet = SPT_RI_STOP_REASON_ERROR;  
                   //(*Client_w_Stress::PClient_Dlg)->memoResults->AppendText (Environment::NewLine + "Callback registers SPT_RI_STOP_REASON_ERROR");
                   //(*Client_w_Stress::PClient_Dlg)->strResultMemo += (Environment::NewLine + "Callback registers SPT_RI_STOP_REASON_ERROR");
                   //RI_AddLineToLog ("Callback registers SPT_RI_STOP_REASON_ERROR");
                 break;
               }
               (*Client_w_Stress::PClient_Dlg)->iStopFired = STOP_FIRED_BY_FEEDBACK;
             }
             else
             {
               lRet = SPT_RI_STOP_REASON_CONTINUE_OK;
             }
           }
           else
           {
             lRet = SPT_RI_STOP_REASON_CONTINUE_OK;
           }
           delete context;
           return lRet;
         }
}

