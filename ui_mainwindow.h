/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Oct 12 21:03:57 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidgetMain;
    QWidget *tab1;
    QGroupBox *groupBoxDetail;
    QLabel *label;
    QLabel *labelARenouvelerPatient;
    QLabel *labelARenouvelerPresDateFin;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labelARenouvelerPresType;
    QLabel *label_5;
    QLabel *labelARenouvelerPresModeR;
    QLabel *labelARenouvelerPresDuree;
    QLabel *label_6;
    QLabel *labelARenouvelerMedNumNom;
    QLabel *labelARenouvelerMedAd2;
    QLabel *label_20;
    QLabel *labelARenouvelerMedAd1;
    QLabel *labelARenouvelerMedCPVille;
    QLabel *labelARenouvelerMedVille;
    QLabel *labelARenouvelerMedTel;
    QGroupBox *groupBox;
    QListWidget *listWidgetPrescriptionsARenouveler;
    QGroupBox *groupBox_2;
    QPushButton *pushButtonARenouvelerRenouveler;
    QDateEdit *dateEditARenouvelerPresDateFin;
    QWidget *tab2;
    QGroupBox *groupBox_9;
    QListWidget *listWidgetPrescriptions;
    QGroupBox *groupBox_10;
    QLabel *label_17;
    QLabel *label_18;
    QComboBox *comboBoxPrescriptionPatient;
    QDateEdit *dateEditPrescriptionDateDebut;
    QLabel *label_19;
    QSpinBox *spinBoxPrescriptionDuree;
    QLabel *label_21;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_25;
    QRadioButton *radioButtonDSI;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonOrdonnance;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonPatient;
    QRadioButton *radioButtonMedecin;
    QGroupBox *groupBox_11;
    QPushButton *pushButtonPrescriptionAjouter;
    QPushButton *pushButtonPrescriptionModifier;
    QPushButton *pushButtonPrescriptionAbandonner;
    QPushButton *pushButtonPrescriptionSupprimer;
    QLineEdit *lineEditRecherchePres;
    QDateEdit *dateEditRecherchePres;
    QSpinBox *spinBoxRecherchePres;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_29;
    QComboBox *comboBoxRecherchePres;
    QLabel *labelMoisRecherchePres;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *radioButtonRechercheChoix1;
    QRadioButton *radioButtonRechercheChoix2;
    QWidget *tab3;
    QGroupBox *groupBox_6;
    QPushButton *pushButtonPatientAjouter;
    QPushButton *pushButtonPatientModifier;
    QPushButton *pushButtonPatientAbandonner;
    QPushButton *pushButtonPatientSupprimer;
    QGroupBox *groupBox_7;
    QListWidget *listWidgetPatients;
    QGroupBox *groupBox_8;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEditPatientNom;
    QLineEdit *lineEditPatientNumSS;
    QLabel *label_16;
    QComboBox *comboBoxPatientMedecin;
    QLineEdit *lineEditRecherchePat;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_28;
    QComboBox *comboBoxRecherchePat;
    QWidget *tab4;
    QGroupBox *groupBox_3;
    QPushButton *pushButtonMedecinAjouter;
    QPushButton *pushButtonMedecinModifier;
    QPushButton *pushButtonMedecinAbandonner;
    QPushButton *pushButtonMedecinSupprimer;
    QGroupBox *groupBox_4;
    QListWidget *listWidgetMedecins;
    QGroupBox *groupBox_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEditMedecinNom;
    QLineEdit *lineEditMedecinNumSS;
    QLineEdit *lineEditMedecinAdr2;
    QLineEdit *lineEditMedecinAdr1;
    QLineEdit *lineEditMedecinCP;
    QLineEdit *lineEditMedecinVille;
    QLabel *label_10;
    QLineEdit *lineEditMedecinTel;
    QLineEdit *lineEditRechercheMed;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_27;
    QComboBox *comboBoxRechercheMed;
    QWidget *tab5;
    QGroupBox *groupBox_12;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEditParametresCPMedecin;
    QLineEdit *lineEditParametreVilleMedecin;
    QGroupBox *groupBox_13;
    QLabel *label_13;
    QLabel *label_22;
    QSpinBox *spinBoxParametreDureeDSI;
    QSpinBox *spinBoxPrescriptionDureeOdronnance;
    QLabel *label_23;
    QLabel *label_24;
    QGroupBox *groupBox_14;
    QPushButton *pushButtonPrescriptionEnregistrer;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_9;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_10;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_11;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(705, 455);
        MainWindow->setMinimumSize(QSize(705, 455));
        MainWindow->setMaximumSize(QSize(705, 455));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidgetMain = new QTabWidget(centralWidget);
        tabWidgetMain->setObjectName(QString::fromUtf8("tabWidgetMain"));
        tabWidgetMain->setGeometry(QRect(10, 10, 700, 450));
        tabWidgetMain->setMinimumSize(QSize(700, 450));
        tabWidgetMain->setMaximumSize(QSize(700, 450));
        QFont font;
        font.setPointSize(10);
        tabWidgetMain->setFont(font);
        tabWidgetMain->setTabPosition(QTabWidget::North);
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        groupBoxDetail = new QGroupBox(tab1);
        groupBoxDetail->setObjectName(QString::fromUtf8("groupBoxDetail"));
        groupBoxDetail->setGeometry(QRect(400, 0, 271, 321));
        groupBoxDetail->setCheckable(false);
        label = new QLabel(groupBoxDetail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 71, 16));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label->setFont(font1);
        labelARenouvelerPatient = new QLabel(groupBoxDetail);
        labelARenouvelerPatient->setObjectName(QString::fromUtf8("labelARenouvelerPatient"));
        labelARenouvelerPatient->setGeometry(QRect(10, 40, 251, 16));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        labelARenouvelerPatient->setFont(font2);
        labelARenouvelerPresDateFin = new QLabel(groupBoxDetail);
        labelARenouvelerPresDateFin->setObjectName(QString::fromUtf8("labelARenouvelerPresDateFin"));
        labelARenouvelerPresDateFin->setGeometry(QRect(140, 90, 111, 16));
        labelARenouvelerPresDateFin->setFont(font2);
        label_2 = new QLabel(groupBoxDetail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 91, 16));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        font3.setStrikeOut(false);
        label_2->setFont(font3);
        label_3 = new QLabel(groupBoxDetail);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 111, 16));
        label_4 = new QLabel(groupBoxDetail);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 130, 141, 16));
        labelARenouvelerPresType = new QLabel(groupBoxDetail);
        labelARenouvelerPresType->setObjectName(QString::fromUtf8("labelARenouvelerPresType"));
        labelARenouvelerPresType->setGeometry(QRect(150, 130, 111, 16));
        labelARenouvelerPresType->setFont(font2);
        label_5 = new QLabel(groupBoxDetail);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 150, 151, 16));
        labelARenouvelerPresModeR = new QLabel(groupBoxDetail);
        labelARenouvelerPresModeR->setObjectName(QString::fromUtf8("labelARenouvelerPresModeR"));
        labelARenouvelerPresModeR->setGeometry(QRect(160, 150, 111, 16));
        labelARenouvelerPresModeR->setFont(font2);
        labelARenouvelerPresDuree = new QLabel(groupBoxDetail);
        labelARenouvelerPresDuree->setObjectName(QString::fromUtf8("labelARenouvelerPresDuree"));
        labelARenouvelerPresDuree->setGeometry(QRect(190, 110, 81, 20));
        labelARenouvelerPresDuree->setFont(font2);
        label_6 = new QLabel(groupBoxDetail);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 110, 161, 16));
        labelARenouvelerMedNumNom = new QLabel(groupBoxDetail);
        labelARenouvelerMedNumNom->setObjectName(QString::fromUtf8("labelARenouvelerMedNumNom"));
        labelARenouvelerMedNumNom->setGeometry(QRect(10, 200, 251, 20));
        labelARenouvelerMedNumNom->setFont(font2);
        labelARenouvelerMedAd2 = new QLabel(groupBoxDetail);
        labelARenouvelerMedAd2->setObjectName(QString::fromUtf8("labelARenouvelerMedAd2"));
        labelARenouvelerMedAd2->setGeometry(QRect(10, 240, 251, 16));
        label_20 = new QLabel(groupBoxDetail);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 180, 91, 16));
        label_20->setFont(font3);
        labelARenouvelerMedAd1 = new QLabel(groupBoxDetail);
        labelARenouvelerMedAd1->setObjectName(QString::fromUtf8("labelARenouvelerMedAd1"));
        labelARenouvelerMedAd1->setGeometry(QRect(0, 220, 251, 16));
        labelARenouvelerMedCPVille = new QLabel(groupBoxDetail);
        labelARenouvelerMedCPVille->setObjectName(QString::fromUtf8("labelARenouvelerMedCPVille"));
        labelARenouvelerMedCPVille->setGeometry(QRect(10, 260, 251, 16));
        labelARenouvelerMedVille = new QLabel(groupBoxDetail);
        labelARenouvelerMedVille->setObjectName(QString::fromUtf8("labelARenouvelerMedVille"));
        labelARenouvelerMedVille->setGeometry(QRect(10, 280, 251, 16));
        labelARenouvelerMedTel = new QLabel(groupBoxDetail);
        labelARenouvelerMedTel->setObjectName(QString::fromUtf8("labelARenouvelerMedTel"));
        labelARenouvelerMedTel->setGeometry(QRect(8, 300, 221, 20));
        groupBox = new QGroupBox(tab1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 381, 391));
        listWidgetPrescriptionsARenouveler = new QListWidget(groupBox);
        listWidgetPrescriptionsARenouveler->setObjectName(QString::fromUtf8("listWidgetPrescriptionsARenouveler"));
        listWidgetPrescriptionsARenouveler->setGeometry(QRect(10, 20, 361, 361));
        groupBox_2 = new QGroupBox(tab1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 330, 271, 61));
        pushButtonARenouvelerRenouveler = new QPushButton(groupBox_2);
        pushButtonARenouvelerRenouveler->setObjectName(QString::fromUtf8("pushButtonARenouvelerRenouveler"));
        pushButtonARenouvelerRenouveler->setEnabled(false);
        pushButtonARenouvelerRenouveler->setGeometry(QRect(140, 20, 111, 23));
        dateEditARenouvelerPresDateFin = new QDateEdit(groupBox_2);
        dateEditARenouvelerPresDateFin->setObjectName(QString::fromUtf8("dateEditARenouvelerPresDateFin"));
        dateEditARenouvelerPresDateFin->setEnabled(false);
        dateEditARenouvelerPresDateFin->setGeometry(QRect(20, 20, 110, 22));
        dateEditARenouvelerPresDateFin->setAlignment(Qt::AlignCenter);
        dateEditARenouvelerPresDateFin->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        tabWidgetMain->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        groupBox_9 = new QGroupBox(tab2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 40, 381, 341));
        listWidgetPrescriptions = new QListWidget(groupBox_9);
        listWidgetPrescriptions->setObjectName(QString::fromUtf8("listWidgetPrescriptions"));
        listWidgetPrescriptions->setGeometry(QRect(10, 20, 361, 351));
        groupBox_10 = new QGroupBox(tab2);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(400, 0, 271, 271));
        label_17 = new QLabel(groupBox_10);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 20, 61, 16));
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_18 = new QLabel(groupBox_10);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 80, 171, 20));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboBoxPrescriptionPatient = new QComboBox(groupBox_10);
        comboBoxPrescriptionPatient->setObjectName(QString::fromUtf8("comboBoxPrescriptionPatient"));
        comboBoxPrescriptionPatient->setGeometry(QRect(10, 40, 251, 22));
        dateEditPrescriptionDateDebut = new QDateEdit(groupBox_10);
        dateEditPrescriptionDateDebut->setObjectName(QString::fromUtf8("dateEditPrescriptionDateDebut"));
        dateEditPrescriptionDateDebut->setGeometry(QRect(10, 100, 101, 22));
        dateEditPrescriptionDateDebut->setAlignment(Qt::AlignCenter);
        dateEditPrescriptionDateDebut->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        label_19 = new QLabel(groupBox_10);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 140, 171, 20));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBoxPrescriptionDuree = new QSpinBox(groupBox_10);
        spinBoxPrescriptionDuree->setObjectName(QString::fromUtf8("spinBoxPrescriptionDuree"));
        spinBoxPrescriptionDuree->setGeometry(QRect(10, 160, 101, 22));
        spinBoxPrescriptionDuree->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(groupBox_10);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(120, 160, 71, 20));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        layoutWidget = new QWidget(groupBox_10);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 190, 208, 28));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_25);

        radioButtonDSI = new QRadioButton(layoutWidget);
        radioButtonDSI->setObjectName(QString::fromUtf8("radioButtonDSI"));
        radioButtonDSI->setChecked(true);

        horizontalLayout_3->addWidget(radioButtonDSI);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButtonOrdonnance = new QRadioButton(layoutWidget);
        radioButtonOrdonnance->setObjectName(QString::fromUtf8("radioButtonOrdonnance"));
        radioButtonOrdonnance->setChecked(false);

        horizontalLayout->addWidget(radioButtonOrdonnance);


        horizontalLayout_3->addLayout(horizontalLayout);

        layoutWidget_2 = new QWidget(groupBox_10);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 230, 212, 28));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_26 = new QLabel(layoutWidget_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_26);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButtonPatient = new QRadioButton(layoutWidget_2);
        radioButtonPatient->setObjectName(QString::fromUtf8("radioButtonPatient"));
        radioButtonPatient->setChecked(true);

        horizontalLayout_2->addWidget(radioButtonPatient);

        radioButtonMedecin = new QRadioButton(layoutWidget_2);
        radioButtonMedecin->setObjectName(QString::fromUtf8("radioButtonMedecin"));

        horizontalLayout_2->addWidget(radioButtonMedecin);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        groupBox_11 = new QGroupBox(tab2);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(400, 270, 271, 111));
        pushButtonPrescriptionAjouter = new QPushButton(groupBox_11);
        pushButtonPrescriptionAjouter->setObjectName(QString::fromUtf8("pushButtonPrescriptionAjouter"));
        pushButtonPrescriptionAjouter->setEnabled(true);
        pushButtonPrescriptionAjouter->setGeometry(QRect(20, 30, 111, 23));
        pushButtonPrescriptionModifier = new QPushButton(groupBox_11);
        pushButtonPrescriptionModifier->setObjectName(QString::fromUtf8("pushButtonPrescriptionModifier"));
        pushButtonPrescriptionModifier->setEnabled(false);
        pushButtonPrescriptionModifier->setGeometry(QRect(140, 30, 111, 23));
        pushButtonPrescriptionAbandonner = new QPushButton(groupBox_11);
        pushButtonPrescriptionAbandonner->setObjectName(QString::fromUtf8("pushButtonPrescriptionAbandonner"));
        pushButtonPrescriptionAbandonner->setEnabled(false);
        pushButtonPrescriptionAbandonner->setGeometry(QRect(20, 70, 111, 23));
        pushButtonPrescriptionSupprimer = new QPushButton(groupBox_11);
        pushButtonPrescriptionSupprimer->setObjectName(QString::fromUtf8("pushButtonPrescriptionSupprimer"));
        pushButtonPrescriptionSupprimer->setEnabled(false);
        pushButtonPrescriptionSupprimer->setGeometry(QRect(140, 70, 111, 23));
        lineEditRecherchePres = new QLineEdit(tab2);
        lineEditRecherchePres->setObjectName(QString::fromUtf8("lineEditRecherchePres"));
        lineEditRecherchePres->setGeometry(QRect(230, 10, 113, 27));
        dateEditRecherchePres = new QDateEdit(tab2);
        dateEditRecherchePres->setObjectName(QString::fromUtf8("dateEditRecherchePres"));
        dateEditRecherchePres->setGeometry(QRect(230, 10, 110, 27));
        spinBoxRecherchePres = new QSpinBox(tab2);
        spinBoxRecherchePres->setObjectName(QString::fromUtf8("spinBoxRecherchePres"));
        spinBoxRecherchePres->setGeometry(QRect(250, 10, 55, 27));
        spinBoxRecherchePres->setValue(3);
        layoutWidget1 = new QWidget(tab2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 10, 204, 29));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_29 = new QLabel(layoutWidget1);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_7->addWidget(label_29);

        comboBoxRecherchePres = new QComboBox(layoutWidget1);
        comboBoxRecherchePres->setObjectName(QString::fromUtf8("comboBoxRecherchePres"));

        horizontalLayout_7->addWidget(comboBoxRecherchePres);

        labelMoisRecherchePres = new QLabel(tab2);
        labelMoisRecherchePres->setObjectName(QString::fromUtf8("labelMoisRecherchePres"));
        labelMoisRecherchePres->setGeometry(QRect(310, 20, 31, 17));
        layoutWidget2 = new QWidget(tab2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(210, 10, 164, 24));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        radioButtonRechercheChoix1 = new QRadioButton(layoutWidget2);
        radioButtonRechercheChoix1->setObjectName(QString::fromUtf8("radioButtonRechercheChoix1"));

        horizontalLayout_8->addWidget(radioButtonRechercheChoix1);

        radioButtonRechercheChoix2 = new QRadioButton(layoutWidget2);
        radioButtonRechercheChoix2->setObjectName(QString::fromUtf8("radioButtonRechercheChoix2"));

        horizontalLayout_8->addWidget(radioButtonRechercheChoix2);

        tabWidgetMain->addTab(tab2, QString());
        labelMoisRecherchePres->raise();
        groupBox_10->raise();
        groupBox_11->raise();
        lineEditRecherchePres->raise();
        dateEditRecherchePres->raise();
        spinBoxRecherchePres->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        groupBox_9->raise();
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        groupBox_6 = new QGroupBox(tab3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(400, 270, 271, 111));
        pushButtonPatientAjouter = new QPushButton(groupBox_6);
        pushButtonPatientAjouter->setObjectName(QString::fromUtf8("pushButtonPatientAjouter"));
        pushButtonPatientAjouter->setEnabled(false);
        pushButtonPatientAjouter->setGeometry(QRect(20, 30, 111, 23));
        pushButtonPatientModifier = new QPushButton(groupBox_6);
        pushButtonPatientModifier->setObjectName(QString::fromUtf8("pushButtonPatientModifier"));
        pushButtonPatientModifier->setEnabled(false);
        pushButtonPatientModifier->setGeometry(QRect(140, 30, 111, 23));
        pushButtonPatientAbandonner = new QPushButton(groupBox_6);
        pushButtonPatientAbandonner->setObjectName(QString::fromUtf8("pushButtonPatientAbandonner"));
        pushButtonPatientAbandonner->setEnabled(false);
        pushButtonPatientAbandonner->setGeometry(QRect(20, 70, 111, 23));
        pushButtonPatientSupprimer = new QPushButton(groupBox_6);
        pushButtonPatientSupprimer->setObjectName(QString::fromUtf8("pushButtonPatientSupprimer"));
        pushButtonPatientSupprimer->setEnabled(false);
        pushButtonPatientSupprimer->setGeometry(QRect(140, 70, 111, 23));
        groupBox_7 = new QGroupBox(tab3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 40, 381, 341));
        listWidgetPatients = new QListWidget(groupBox_7);
        listWidgetPatients->setObjectName(QString::fromUtf8("listWidgetPatients"));
        listWidgetPatients->setGeometry(QRect(10, 20, 361, 351));
        groupBox_8 = new QGroupBox(tab3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(400, 0, 271, 271));
        label_14 = new QLabel(groupBox_8);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 20, 61, 16));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 80, 171, 20));
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEditPatientNom = new QLineEdit(groupBox_8);
        lineEditPatientNom->setObjectName(QString::fromUtf8("lineEditPatientNom"));
        lineEditPatientNom->setGeometry(QRect(10, 40, 251, 20));
        lineEditPatientNom->setMaxLength(50);
        lineEditPatientNumSS = new QLineEdit(groupBox_8);
        lineEditPatientNumSS->setObjectName(QString::fromUtf8("lineEditPatientNumSS"));
        lineEditPatientNumSS->setGeometry(QRect(10, 100, 251, 20));
        lineEditPatientNumSS->setMaxLength(30);
        label_16 = new QLabel(groupBox_8);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 140, 131, 16));
        comboBoxPatientMedecin = new QComboBox(groupBox_8);
        comboBoxPatientMedecin->setObjectName(QString::fromUtf8("comboBoxPatientMedecin"));
        comboBoxPatientMedecin->setGeometry(QRect(10, 160, 251, 22));
        lineEditRecherchePat = new QLineEdit(tab3);
        lineEditRecherchePat->setObjectName(QString::fromUtf8("lineEditRecherchePat"));
        lineEditRecherchePat->setEnabled(false);
        lineEditRecherchePat->setGeometry(QRect(250, 10, 113, 27));
        layoutWidget3 = new QWidget(tab3);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 10, 238, 29));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_28 = new QLabel(layoutWidget3);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_6->addWidget(label_28);

        comboBoxRecherchePat = new QComboBox(layoutWidget3);
        comboBoxRecherchePat->setObjectName(QString::fromUtf8("comboBoxRecherchePat"));

        horizontalLayout_6->addWidget(comboBoxRecherchePat);

        tabWidgetMain->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QString::fromUtf8("tab4"));
        groupBox_3 = new QGroupBox(tab4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(400, 270, 271, 111));
        pushButtonMedecinAjouter = new QPushButton(groupBox_3);
        pushButtonMedecinAjouter->setObjectName(QString::fromUtf8("pushButtonMedecinAjouter"));
        pushButtonMedecinAjouter->setEnabled(false);
        pushButtonMedecinAjouter->setGeometry(QRect(20, 30, 111, 23));
        pushButtonMedecinModifier = new QPushButton(groupBox_3);
        pushButtonMedecinModifier->setObjectName(QString::fromUtf8("pushButtonMedecinModifier"));
        pushButtonMedecinModifier->setEnabled(false);
        pushButtonMedecinModifier->setGeometry(QRect(140, 30, 111, 23));
        pushButtonMedecinAbandonner = new QPushButton(groupBox_3);
        pushButtonMedecinAbandonner->setObjectName(QString::fromUtf8("pushButtonMedecinAbandonner"));
        pushButtonMedecinAbandonner->setEnabled(false);
        pushButtonMedecinAbandonner->setGeometry(QRect(20, 70, 111, 23));
        pushButtonMedecinSupprimer = new QPushButton(groupBox_3);
        pushButtonMedecinSupprimer->setObjectName(QString::fromUtf8("pushButtonMedecinSupprimer"));
        pushButtonMedecinSupprimer->setEnabled(false);
        pushButtonMedecinSupprimer->setGeometry(QRect(140, 70, 111, 23));
        groupBox_4 = new QGroupBox(tab4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 40, 381, 341));
        listWidgetMedecins = new QListWidget(groupBox_4);
        listWidgetMedecins->setObjectName(QString::fromUtf8("listWidgetMedecins"));
        listWidgetMedecins->setGeometry(QRect(10, 20, 361, 351));
        groupBox_5 = new QGroupBox(tab4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(400, 0, 271, 271));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 61, 16));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 60, 111, 20));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 110, 61, 16));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEditMedecinNom = new QLineEdit(groupBox_5);
        lineEditMedecinNom->setObjectName(QString::fromUtf8("lineEditMedecinNom"));
        lineEditMedecinNom->setGeometry(QRect(10, 40, 251, 20));
        lineEditMedecinNom->setMaxLength(50);
        lineEditMedecinNumSS = new QLineEdit(groupBox_5);
        lineEditMedecinNumSS->setObjectName(QString::fromUtf8("lineEditMedecinNumSS"));
        lineEditMedecinNumSS->setGeometry(QRect(10, 80, 251, 20));
        lineEditMedecinNumSS->setMaxLength(15);
        lineEditMedecinAdr2 = new QLineEdit(groupBox_5);
        lineEditMedecinAdr2->setObjectName(QString::fromUtf8("lineEditMedecinAdr2"));
        lineEditMedecinAdr2->setGeometry(QRect(10, 160, 251, 20));
        lineEditMedecinAdr2->setMaxLength(50);
        lineEditMedecinAdr1 = new QLineEdit(groupBox_5);
        lineEditMedecinAdr1->setObjectName(QString::fromUtf8("lineEditMedecinAdr1"));
        lineEditMedecinAdr1->setGeometry(QRect(10, 130, 251, 20));
        lineEditMedecinAdr1->setMaxLength(50);
        lineEditMedecinCP = new QLineEdit(groupBox_5);
        lineEditMedecinCP->setObjectName(QString::fromUtf8("lineEditMedecinCP"));
        lineEditMedecinCP->setGeometry(QRect(10, 190, 71, 20));
        lineEditMedecinCP->setMaxLength(5);
        lineEditMedecinCP->setAlignment(Qt::AlignCenter);
        lineEditMedecinVille = new QLineEdit(groupBox_5);
        lineEditMedecinVille->setObjectName(QString::fromUtf8("lineEditMedecinVille"));
        lineEditMedecinVille->setGeometry(QRect(90, 190, 171, 20));
        lineEditMedecinVille->setMaxLength(50);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 220, 81, 16));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEditMedecinTel = new QLineEdit(groupBox_5);
        lineEditMedecinTel->setObjectName(QString::fromUtf8("lineEditMedecinTel"));
        lineEditMedecinTel->setGeometry(QRect(10, 240, 251, 20));
        lineEditMedecinTel->setMaxLength(50);
        lineEditRechercheMed = new QLineEdit(tab4);
        lineEditRechercheMed->setObjectName(QString::fromUtf8("lineEditRechercheMed"));
        lineEditRechercheMed->setEnabled(false);
        lineEditRechercheMed->setGeometry(QRect(240, 10, 113, 27));
        layoutWidget4 = new QWidget(tab4);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 10, 211, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(layoutWidget4);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_5->addWidget(label_27);

        comboBoxRechercheMed = new QComboBox(layoutWidget4);
        comboBoxRechercheMed->setObjectName(QString::fromUtf8("comboBoxRechercheMed"));

        horizontalLayout_5->addWidget(comboBoxRechercheMed);

        tabWidgetMain->addTab(tab4, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QString::fromUtf8("tab5"));
        groupBox_12 = new QGroupBox(tab5);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(10, 10, 661, 91));
        label_11 = new QLabel(groupBox_12);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 30, 111, 16));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_12 = new QLabel(groupBox_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 60, 101, 16));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditParametresCPMedecin = new QLineEdit(groupBox_12);
        lineEditParametresCPMedecin->setObjectName(QString::fromUtf8("lineEditParametresCPMedecin"));
        lineEditParametresCPMedecin->setGeometry(QRect(160, 30, 101, 20));
        lineEditParametresCPMedecin->setMaxLength(5);
        lineEditParametreVilleMedecin = new QLineEdit(groupBox_12);
        lineEditParametreVilleMedecin->setObjectName(QString::fromUtf8("lineEditParametreVilleMedecin"));
        lineEditParametreVilleMedecin->setGeometry(QRect(160, 60, 491, 20));
        lineEditParametreVilleMedecin->setMaxLength(50);
        groupBox_13 = new QGroupBox(tab5);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(10, 110, 661, 91));
        label_13 = new QLabel(groupBox_13);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 30, 121, 16));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_22 = new QLabel(groupBox_13);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 60, 131, 20));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxParametreDureeDSI = new QSpinBox(groupBox_13);
        spinBoxParametreDureeDSI->setObjectName(QString::fromUtf8("spinBoxParametreDureeDSI"));
        spinBoxParametreDureeDSI->setGeometry(QRect(160, 30, 81, 22));
        spinBoxParametreDureeDSI->setAlignment(Qt::AlignCenter);
        spinBoxPrescriptionDureeOdronnance = new QSpinBox(groupBox_13);
        spinBoxPrescriptionDureeOdronnance->setObjectName(QString::fromUtf8("spinBoxPrescriptionDureeOdronnance"));
        spinBoxPrescriptionDureeOdronnance->setGeometry(QRect(160, 60, 81, 22));
        spinBoxPrescriptionDureeOdronnance->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(groupBox_13);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(250, 60, 46, 14));
        label_24 = new QLabel(groupBox_13);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(250, 30, 46, 14));
        groupBox_14 = new QGroupBox(tab5);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(10, 320, 661, 80));
        pushButtonPrescriptionEnregistrer = new QPushButton(groupBox_14);
        pushButtonPrescriptionEnregistrer->setObjectName(QString::fromUtf8("pushButtonPrescriptionEnregistrer"));
        pushButtonPrescriptionEnregistrer->setGeometry(QRect(90, 30, 111, 23));
        tabWidgetMain->addTab(tab5, QString());
        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        layoutWidget6 = new QWidget(centralWidget);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        layoutWidget7 = new QWidget(centralWidget);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidgetMain->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion d'Ordonnance et DSI", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidgetMain->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBoxDetail->setTitle(QApplication::translate("MainWindow", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Patient :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerPatient->setText(QString());
        labelARenouvelerPresDateFin->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Prescription :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Valable jusqu'au :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Type de prescription :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerPresType->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Mode renouvellement :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerPresModeR->setText(QString());
        labelARenouvelerPresDuree->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Dur\303\251e de la prescription :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerMedNumNom->setText(QString());
        labelARenouvelerMedAd2->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "M\303\251decin :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerMedAd1->setText(QString());
        labelARenouvelerMedCPVille->setText(QString());
        labelARenouvelerMedVille->setText(QString());
        labelARenouvelerMedTel->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "A renouveler rapidement", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
        pushButtonARenouvelerRenouveler->setText(QApplication::translate("MainWindow", "Renouveler", 0, QApplication::UnicodeUTF8));
        dateEditARenouvelerPresDateFin->setDisplayFormat(QApplication::translate("MainWindow", "dd-MM-yyyy", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab1), QApplication::translate("MainWindow", "A renouveler", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Prescriptions enregistr\303\251es", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Saisie", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Patient * :", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Date de d\303\251but :", 0, QApplication::UnicodeUTF8));
        dateEditPrescriptionDateDebut->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Dur\303\251e :", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "mois", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "Type :", 0, QApplication::UnicodeUTF8));
        radioButtonDSI->setText(QApplication::translate("MainWindow", "DSI", 0, QApplication::UnicodeUTF8));
        radioButtonOrdonnance->setText(QApplication::translate("MainWindow", "Ordonnance", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "Mode :", 0, QApplication::UnicodeUTF8));
        radioButtonPatient->setText(QApplication::translate("MainWindow", "Patient", 0, QApplication::UnicodeUTF8));
        radioButtonMedecin->setText(QApplication::translate("MainWindow", "Medecin", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "Actions", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionAjouter->setText(QApplication::translate("MainWindow", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionModifier->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionAbandonner->setText(QApplication::translate("MainWindow", "Abandonner", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "Rechercher par ", 0, QApplication::UnicodeUTF8));
        comboBoxRecherchePres->clear();
        comboBoxRecherchePres->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Pas de tri", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Numero", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Patient", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Date de fin", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Duree", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8)
        );
        labelMoisRecherchePres->setText(QApplication::translate("MainWindow", "mois", 0, QApplication::UnicodeUTF8));
        radioButtonRechercheChoix1->setText(QApplication::translate("MainWindow", "DSI", 0, QApplication::UnicodeUTF8));
        radioButtonRechercheChoix2->setText(QApplication::translate("MainWindow", "Ordonnance", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab2), QApplication::translate("MainWindow", "Prescriptions", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Actions", 0, QApplication::UnicodeUTF8));
        pushButtonPatientAjouter->setText(QApplication::translate("MainWindow", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButtonPatientModifier->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButtonPatientAbandonner->setText(QApplication::translate("MainWindow", "Abandonner", 0, QApplication::UnicodeUTF8));
        pushButtonPatientSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Patients enregistr\303\251s", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Saisie", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Nom * :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Num\303\251ro S\303\251curit\303\251 Sociale :", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "M\303\251decin traitant :", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "Rechercher par ", 0, QApplication::UnicodeUTF8));
        comboBoxRecherchePat->clear();
        comboBoxRecherchePat->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Pas de tri", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Num", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Nom", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Num SS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Medecin traitant", 0, QApplication::UnicodeUTF8)
        );
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab3), QApplication::translate("MainWindow", "Patients", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Actions", 0, QApplication::UnicodeUTF8));
        pushButtonMedecinAjouter->setText(QApplication::translate("MainWindow", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButtonMedecinModifier->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButtonMedecinAbandonner->setText(QApplication::translate("MainWindow", "Abandonner", 0, QApplication::UnicodeUTF8));
        pushButtonMedecinSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Medecins enregistr\303\251s", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Saisie", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Nom * :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Num\303\251ro CPAM * :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Adresse :", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "T\303\251l\303\251phones :", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "Rechercher par : ", 0, QApplication::UnicodeUTF8));
        comboBoxRechercheMed->clear();
        comboBoxRechercheMed->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Pas de tri", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Num", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Nom", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CPAM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Adresse", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Ville", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Telephone", 0, QApplication::UnicodeUTF8)
        );
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab4), QApplication::translate("MainWindow", "M\303\251decins", 0, QApplication::UnicodeUTF8));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "M\303\251decin [valeurs par d\303\251faut]", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Code postal :", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Ville :", 0, QApplication::UnicodeUTF8));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "Prescriptions  [valeurs par d\303\251faut]", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Dur\303\251e DSI :", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Dur\303\251e ordonnance :", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "mois", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "mois", 0, QApplication::UnicodeUTF8));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab5), QApplication::translate("MainWindow", "Param\303\250tres", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
