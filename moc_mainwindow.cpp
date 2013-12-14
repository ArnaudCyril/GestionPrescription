/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Oct 12 21:41:01 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,
      61,   12,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     146,   11,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     226,   11,   11,   11, 0x08,
     271,  269,   11,   11, 0x08,
     327,   12,   11,   11, 0x08,
     377,  269,   11,   11, 0x08,
     432,   12,   11,   11, 0x08,
     481,   12,   11,   11, 0x08,
     530,  269,   11,   11, 0x08,
     596,  585,   11,   11, 0x08,
     657,   11,   11,   11, 0x08,
     708,   11,   11,   11, 0x08,
     740,   11,   11,   11, 0x08,
     775,   11,   11,   11, 0x08,
     807,   11,   11,   11, 0x08,
     835,   11,   11,   11, 0x08,
     881,   12,   11,   11, 0x08,
     937,   11,   11,   11, 0x08,
     984,   11,   11,   11, 0x08,
    1040,   11,   11,   11, 0x08,
    1086,  269,   11,   11, 0x08,
    1150,  269,   11,   11, 0x08,
    1212,   12,   11,   11, 0x08,
    1249,   11,   11,   11, 0x08,
    1290,   11,   11,   11, 0x08,
    1330,   11,   11,   11, 0x08,
    1368,   11,   11,   11, 0x08,
    1407,  269,   11,   11, 0x08,
    1460,  269,   11,   11, 0x08,
    1515,  269,   11,   11, 0x08,
    1567,  269,   11,   11, 0x08,
    1621,  269,   11,   11, 0x08,
    1675,  269,   11,   11, 0x08,
    1730,  269,   11,   11, 0x08,
    1783,   11,   11,   11, 0x08,
    1828,   11,   11,   11, 0x08,
    1868,   11,   11,   11, 0x08,
    1909,   11,   11,   11, 0x08,
    1947,   11,   11,   11, 0x08,
    1986,  269,   11,   11, 0x08,
    2041,  269,   11,   11, 0x08,
    2094,   11,   11,   11, 0x08,
    2139,   12,   11,   11, 0x08,
    2187,   11,   11,   11, 0x08,
    2233,   11,   11,   11, 0x08,
    2278,   11,   11,   11, 0x08,
    2321,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0index\0"
    "on_listWidgetPatients_clicked(QModelIndex)\0"
    "on_listWidgetMedecins_clicked(QModelIndex)\0"
    "on_spinBoxRecherchePres_valueChanged(int)\0"
    "on_radioButtonRechercheChoix1_clicked()\0"
    "on_radioButtonRechercheChoix2_clicked()\0"
    "on_dateEditRecherchePres_editingFinished()\0"
    ",\0on_lineEditRecherchePres_cursorPositionChanged(int,int)\0"
    "on_comboBoxRecherchePres_currentIndexChanged(int)\0"
    "on_lineEditRecherchePat_cursorPositionChanged(int,int)\0"
    "on_comboBoxRecherchePat_currentIndexChanged(int)\0"
    "on_comboBoxRechercheMed_currentIndexChanged(int)\0"
    "on_lineEditRechercheMed_cursorPositionChanged(int,int)\0"
    "currentRow\0"
    "on_listWidgetPrescriptionsARenouveler_currentRowChanged(int)\0"
    "on_dateEditPrescriptionDateDebut_editingFinished()\0"
    "on_radioButtonMedecin_clicked()\0"
    "on_radioButtonOrdonnance_clicked()\0"
    "on_radioButtonPatient_clicked()\0"
    "on_radioButtonDSI_clicked()\0"
    "on_spinBoxPrescriptionDuree_valueChanged(int)\0"
    "on_comboBoxPrescriptionPatient_currentIndexChanged(int)\0"
    "on_pushButtonPrescriptionEnregistrer_clicked()\0"
    "on_spinBoxPrescriptionDureeOdronnance_valueChanged(int)\0"
    "on_spinBoxParametreDureeDSI_valueChanged(int)\0"
    "on_lineEditParametreVilleMedecin_cursorPositionChanged(int,int)\0"
    "on_lineEditParametresCPMedecin_cursorPositionChanged(int,int)\0"
    "on_tabWidgetMain_currentChanged(int)\0"
    "on_pushButtonMedecinAbandonner_clicked()\0"
    "on_pushButtonMedecinSupprimer_clicked()\0"
    "on_pushButtonMedecinAjouter_clicked()\0"
    "on_pushButtonMedecinModifier_clicked()\0"
    "on_lineEditMedecinTel_cursorPositionChanged(int,int)\0"
    "on_lineEditMedecinVille_cursorPositionChanged(int,int)\0"
    "on_lineEditMedecinCP_cursorPositionChanged(int,int)\0"
    "on_lineEditMedecinAdr2_cursorPositionChanged(int,int)\0"
    "on_lineEditMedecinAdr1_cursorPositionChanged(int,int)\0"
    "on_lineEditMedecinNumSS_cursorPositionChanged(int,int)\0"
    "on_lineEditMedecinNom_cursorPositionChanged(int,int)\0"
    "on_comboBoxPatientMedecin_activated(QString)\0"
    "on_pushButtonPatientSupprimer_clicked()\0"
    "on_pushButtonPatientAbandonner_clicked()\0"
    "on_pushButtonPatientAjouter_clicked()\0"
    "on_pushButtonPatientModifier_clicked()\0"
    "on_lineEditPatientNumSS_cursorPositionChanged(int,int)\0"
    "on_lineEditPatientNom_cursorPositionChanged(int,int)\0"
    "on_pushButtonARenouvelerRenouveler_clicked()\0"
    "on_listWidgetPrescriptions_clicked(QModelIndex)\0"
    "on_pushButtonPrescriptionAbandonner_clicked()\0"
    "on_pushButtonPrescriptionSupprimer_clicked()\0"
    "on_pushButtonPrescriptionAjouter_clicked()\0"
    "on_pushButtonPrescriptionModifier_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_listWidgetPatients_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: on_listWidgetMedecins_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: on_spinBoxRecherchePres_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_radioButtonRechercheChoix1_clicked(); break;
        case 4: on_radioButtonRechercheChoix2_clicked(); break;
        case 5: on_dateEditRecherchePres_editingFinished(); break;
        case 6: on_lineEditRecherchePres_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: on_comboBoxRecherchePres_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_lineEditRecherchePat_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: on_comboBoxRecherchePat_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_comboBoxRechercheMed_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: on_lineEditRechercheMed_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: on_listWidgetPrescriptionsARenouveler_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: on_dateEditPrescriptionDateDebut_editingFinished(); break;
        case 14: on_radioButtonMedecin_clicked(); break;
        case 15: on_radioButtonOrdonnance_clicked(); break;
        case 16: on_radioButtonPatient_clicked(); break;
        case 17: on_radioButtonDSI_clicked(); break;
        case 18: on_spinBoxPrescriptionDuree_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: on_comboBoxPrescriptionPatient_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: on_pushButtonPrescriptionEnregistrer_clicked(); break;
        case 21: on_spinBoxPrescriptionDureeOdronnance_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: on_spinBoxParametreDureeDSI_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: on_lineEditParametreVilleMedecin_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: on_lineEditParametresCPMedecin_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: on_tabWidgetMain_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: on_pushButtonMedecinAbandonner_clicked(); break;
        case 27: on_pushButtonMedecinSupprimer_clicked(); break;
        case 28: on_pushButtonMedecinAjouter_clicked(); break;
        case 29: on_pushButtonMedecinModifier_clicked(); break;
        case 30: on_lineEditMedecinTel_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 31: on_lineEditMedecinVille_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 32: on_lineEditMedecinCP_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: on_lineEditMedecinAdr2_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: on_lineEditMedecinAdr1_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: on_lineEditMedecinNumSS_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: on_lineEditMedecinNom_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 37: on_comboBoxPatientMedecin_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 38: on_pushButtonPatientSupprimer_clicked(); break;
        case 39: on_pushButtonPatientAbandonner_clicked(); break;
        case 40: on_pushButtonPatientAjouter_clicked(); break;
        case 41: on_pushButtonPatientModifier_clicked(); break;
        case 42: on_lineEditPatientNumSS_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 43: on_lineEditPatientNom_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 44: on_pushButtonARenouvelerRenouveler_clicked(); break;
        case 45: on_listWidgetPrescriptions_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 46: on_pushButtonPrescriptionAbandonner_clicked(); break;
        case 47: on_pushButtonPrescriptionSupprimer_clicked(); break;
        case 48: on_pushButtonPrescriptionAjouter_clicked(); break;
        case 49: on_pushButtonPrescriptionModifier_clicked(); break;
        default: ;
        }
        _id -= 50;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
