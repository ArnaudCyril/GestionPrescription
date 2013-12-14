#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QVector>
#include <QModelIndex>
#include <QListWidgetItem>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    bool nonVide();// methode de vérification (infos vides et différentes)
    bool nonVide2();
    bool estDifferent();
    bool nonVideMed();
    bool nonVideMed2();
    bool estDifferentMed();
    bool estDifferenteParam();
    bool nonVideParam();
    bool nonVidePres();
    bool estDifferentPres();

    bool patientChoisi;// variables qui determinent si on a cliqué sur un item
    bool medChoisi;
    bool presChoisie;
    bool triggerNonRadio;

    int gererBoutonRadio();// méthode qui revoi l id de l item selectionné
    int gererBoutonRadio2();
    int gererBoutonRadioRecherche();

    QSqlDatabase base; // declaration de la base
     QVector<int> vectorIdPatient; // declaration des vecteurs
     QVector<int> vectorId;
     QVector<int> vectorIdPrescritption;
     QVector<int> vectorIdPatients;
     QVector<int> vectorIdPatientMedecin;
     QVector<int> vectorIdMedecin;
     QVector<int> vectorIdPres;

    QString AjoutRechercheMed();// méthodes qui ajoutent éventuellement des conditions a une requette
    QString AjoutRecherchePat();
    QString AjoutRecherchePres();

     QString nom; // variables qui permettent la conparaison et la gestion des bouttons modifier et ajouter ---- patient
     QString noSS;

     int indexCombo;
     QString nomMed; // ---- medecin
     QString noSSMed;
     QString adr1;
     QString adr2;
     QString cp;
     QString ville;
     QString tel;
                    // -----prescrption
     QString presPatient;
     QString datePres;
     int dureePres;
     int dsiOrOrdo;
     int patOrMed;
     int indexComboRecherchePres;// variable qui permet la gestion de l affichage de recherche

    Ui::MainWindow *ui;
    void ouvreBase();//ouverture et appel sa cr��ation si besoin de la base de donn��es
    void fermeBase();//...
    void chargerPrescription();//charge l onglet a renouveler
    void chargerListeMedecin();//charge l onglet medecin
    void clearAll();// netoie tout sur la page a renouveler
    void chargeListePatients();// charge l onglet patient
    void chargeListePatientMedecin(); //combo des m��decin dans l'onglet patient
    void chargerParametres();// charge l onglet parametres
    void chargerListePrescription(); // charge l onglet prescription
    void gereButtonMed();// methode qui gere l activation des bouttons sur l onglet medecin
    QString jours(int);
    void getColor(QListWidgetItem*,int);// methode qui ajoute une couleur a l item
    void verifBase();//v��rifie le sch��ma de la base de donn��es et le cr��e au besoin
    void chargeListePresPatient(); // combo box des patients dans l onglet prescription
    void setButtonPres(int,int);  // methode qui coche les boutton radio selon les valeurs passée en parametres
    void gererButtonPres();// methode qui gere l activation des bouttons sur l onglet prescription
    void gereButtonPat();// methode qui gere l activation des bouttons sur l onglet patient
    void gereButtonParam();// methode qui gere l activation des bouttons sur l onglet parametre
    void setDuree(); // méthode qui remplie la spin box avec la valeur par defeut selon si c est une dsi ou ordonncance
    void gererAffichageRecherche();// methode qui gere l affiche des element a afficher selon le critere de recherche

private slots:

        // liste des slots
    void on_listWidgetPatients_clicked(QModelIndex index);
    void on_listWidgetMedecins_clicked(QModelIndex index);
    void on_spinBoxRecherchePres_valueChanged(int );
    void on_radioButtonRechercheChoix1_clicked();
    void on_radioButtonRechercheChoix2_clicked();
    void on_dateEditRecherchePres_editingFinished();
    void on_lineEditRecherchePres_cursorPositionChanged(int , int );
    void on_comboBoxRecherchePres_currentIndexChanged(int index);
    void on_lineEditRecherchePat_cursorPositionChanged(int , int );
    void on_comboBoxRecherchePat_currentIndexChanged(int index);
    void on_comboBoxRechercheMed_currentIndexChanged(int index);
    void on_lineEditRechercheMed_cursorPositionChanged(int , int );

    void on_listWidgetPrescriptionsARenouveler_currentRowChanged(int currentRow);
    void on_dateEditPrescriptionDateDebut_editingFinished();
    void on_radioButtonMedecin_clicked();
    void on_radioButtonOrdonnance_clicked();
    void on_radioButtonPatient_clicked();
    void on_radioButtonDSI_clicked();
    void on_spinBoxPrescriptionDuree_valueChanged(int );
    void on_comboBoxPrescriptionPatient_currentIndexChanged(int index);
    void on_pushButtonPrescriptionEnregistrer_clicked();
    void on_spinBoxPrescriptionDureeOdronnance_valueChanged(int );
    void on_spinBoxParametreDureeDSI_valueChanged(int );
    void on_lineEditParametreVilleMedecin_cursorPositionChanged(int , int );
    void on_lineEditParametresCPMedecin_cursorPositionChanged(int , int );
    void on_tabWidgetMain_currentChanged(int index);
    void on_pushButtonMedecinAbandonner_clicked();
    void on_pushButtonMedecinSupprimer_clicked();
    void on_pushButtonMedecinAjouter_clicked();
    void on_pushButtonMedecinModifier_clicked();
    void on_lineEditMedecinTel_cursorPositionChanged(int , int );
    void on_lineEditMedecinVille_cursorPositionChanged(int , int );
    void on_lineEditMedecinCP_cursorPositionChanged(int , int );
    void on_lineEditMedecinAdr2_cursorPositionChanged(int , int );
    void on_lineEditMedecinAdr1_cursorPositionChanged(int , int );
    void on_lineEditMedecinNumSS_cursorPositionChanged(int , int );
    void on_lineEditMedecinNom_cursorPositionChanged(int , int );  
    void on_comboBoxPatientMedecin_activated(QString );
    void on_pushButtonPatientSupprimer_clicked();
    void on_pushButtonPatientAbandonner_clicked();
    void on_pushButtonPatientAjouter_clicked();
    void on_pushButtonPatientModifier_clicked();
    void on_lineEditPatientNumSS_cursorPositionChanged(int , int );
    void on_lineEditPatientNom_cursorPositionChanged(int , int );
    void on_pushButtonARenouvelerRenouveler_clicked();



    void on_listWidgetPrescriptions_clicked(const QModelIndex &index);
    void on_pushButtonPrescriptionAbandonner_clicked();
    void on_pushButtonPrescriptionSupprimer_clicked();
    void on_pushButtonPrescriptionAjouter_clicked();
    void on_pushButtonPrescriptionModifier_clicked();
};

#endif // MAINWINDOW_H
