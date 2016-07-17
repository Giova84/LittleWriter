class ResizeImageDialog : public QDialog
{
    Q_OBJECT

double                   m_ratio;

QLabel                  *m_widthLabel;
QLabel                  *m_hightLabel;
QDoubleSpinBox          *m_widthSpinBox;
QDoubleSpinBox          *m_hightSpinBox;
QCheckBox               *m_keepRatioCheckBox;

QPushButton             *m_okButton;
QPushButton             *m_cancelButton;

QHBoxLayout             *m_widthLayout;
QHBoxLayout             *m_hightLayout;
QHBoxLayout             *m_buttonLayout;
QVBoxLayout             *m_generalLayout;

private slots:
    void widthChanged(double width);
    void hightChanged(double hight);

public:
    ResizeImageDialog(QWidget * parent = 0, double imageWidth = 100.0, double imageHight = 100.0):QDialog(parent)
    {
    m_widthLabel = new QLabel("Image width");
    m_hightLabel = new QLabel("Image hight");

    m_widthSpinBox = new QDoubleSpinBox;
    m_widthSpinBox->setMaximum(1500);
    m_widthSpinBox->setValue(imageWidth);
    connect(m_widthSpinBox, SIGNAL(valueChanged(double)), this, SLOT(widthChanged(double)));


    m_hightSpinBox = new QDoubleSpinBox;
    m_hightSpinBox->setMaximum(1500);
    m_hightSpinBox->setValue(imageHight);
    connect(m_hightSpinBox, SIGNAL(valueChanged(double)), this, SLOT(hightChanged(double)));

    m_ratio = imageWidth/imageHight;


    m_keepRatioCheckBox = new QCheckBox("Keep ratio",this);
    m_keepRatioCheckBox->setChecked(true);


    m_widthLayout = new QHBoxLayout;
    m_widthLayout->addWidget(m_widthLabel);
    m_widthLayout->addWidget(m_widthSpinBox);

    m_hightLayout  = new QHBoxLayout;
    m_hightLayout->addWidget(m_hightLabel);
    m_hightLayout->addWidget(m_hightSpinBox);

    m_okButton = new QPushButton("OK");
    connect(m_okButton, SIGNAL(clicked()), this, SLOT(accept()));

    m_cancelButton = new QPushButton("Cancel");
    connect(m_cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    m_buttonLayout = new QHBoxLayout;
    m_buttonLayout->addStretch();
    m_buttonLayout->addWidget(m_okButton);
    m_buttonLayout->addWidget(m_cancelButton);

    m_generalLayout = new QVBoxLayout;
    m_generalLayout->addLayout(m_widthLayout);
    m_generalLayout->addLayout(m_hightLayout);
    m_generalLayout->addWidget(m_keepRatioCheckBox);
    m_generalLayout->addLayout(m_buttonLayout);
    setLayout(m_generalLayout);

    setMaximumSize(300, 300);
    setModal(true);
    //resize(670,630);
    setWindowTitle(tr("Resize Image"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

static QPair<double, double> getNewSize(QWidget * parent = 0, double imageWidth = 100.0, double imageHight = 100.0)
{
    ResizeImageDialog dlg(parent, imageWidth, imageHight);
    dlg.exec();



    QPair<double, double> size;
    size.first = dlg.m_widthSpinBox->value();
    size.second = dlg.m_hightSpinBox->value();
    return size;
}
};