#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>

//Constructeur du Mainwindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    this->ouvreBase();//on ouvre/crée la base sqlite

    chargerPrescription(); //on charge les onglets grace aux méthodes appropriées-onglet 1

    chargerListePrescription();
    indexComboRecherchePres=-1;//onglet 2

    chargeListePatients(); // onglet 3

    chargerListeMedecin();
    // onglet 4

    chargerParametres(); //onglet 5

}

MainWindow::~MainWindow()
{
    // destructeur de la mainwindow
    fermeBase();
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::ouvreBase()
{
    base=QSqlDatabase::addDatabase("QSQLITE");
    //nom fichier qui contient la base sqlite3
    base.setDatabaseName("GestionPrescription.db");

    //ouverture de la base de donnees
    base.open();

    //si la base ne s'est pas ouverte correctement
    if(base.isOpen() != true){
            QMessageBox::critical(this, "Erreur critique", "Impossible d'ouvrir la base de données.");
        }
    else{
            this->verifBase();//si la base s'est ouverte , on verifie si elle est vide ou non.
    }
}
void MainWindow::verifBase()
{
    this->base.exec("select patNum, patNom, patNumSS,patDoc from Patient;");  //on requette tout les champs de chaque tables pour s'assurer l'existence de chaque champ
    this->base.exec("select docNum, docNom, docNumSS,docAdresse1,docAdresse2,docCP,docVille,docTel from Medecin;");
    this->base.exec("select presNum, presDuree, presDate,presModeRenouv,presType,patNum from Prescription;");
    this->base.exec("select codePostal,ville,dureeDsi,dureeOrdonnance from Parametres;");


    if (this->base.lastError().number()>0)//si la requete renvoie une erreur
    {
 
                                                                                                              

       this->base.exec("begin;"); //début transaction SQL

        this->base.exec("drop table if exists Patient;");  //création des tables 
        this->base.exec("create table Patient(patNum smallint  primary key,patNom varchar (30),patNumSS varchar (15),patDoc smallint,FOREIGN KEY(patDoc) REFERENCES Medecin(docNum));");
        this->base.exec("drop table if exists Medecin;");
        this->base.exec("create table Medecin(docNum smallint  primary key ,docNom varchar(30),docNumSS varchar(15),docAdresse1 varchar(50),docAdresse2 varchar(50),docCP varchar(6),docVille varchar(40),docTel varchar (15));");
        this->base.exec("drop table if exists Prescription;");
        this->base.exec("create table Prescription(presNum smallint primary key ,presDuree smallint,presDate date,presModeRenouv tinyint,presType tinyint,patNum smallint,FOREIGN KEY(patNum) REFERENCES Patient(patNum));");
        //note : 1 => Patient et 2 => Medecin//1 => DSI et 2 => Prescription
        //note l'auto increment de semble pas marcher (aucune valeur rentrée si on met null..)
        this->base.exec("drop table if exists Parametres;");
        this->base.exec("create table Parametres(codePostal varchar(6),ville varchar(30),dureeDsi tinyint,dureeOrdonnance tinynt);");

        //création d'un jeu d'essai pour tester l'application
        
        this->base.exec("insert into Medecin values(1,'Legrand','987456321987456','Route de la Victoire','Batiement A','05000','Gap','0612354547');");
        this->base.exec("insert into Medecin values(2,'Thomassin','123654789521045','Route du Code a 2 doigts','Batiement C','05000','Gap','0698745632');");
        this->base.exec("insert into Medecin values(3,'Trudeau','147852369852147','Route de la deception','Batiement Z','75000','Paris','0615254785');");

        this->base.exec("insert into Patient values(1,'Deliancourt','123456789874563',1);");
        this->base.exec("insert into Patient values(2,'Delienne','102378945632578',2);");
        this->base.exec("insert into Patient values(3,'Arnaud','123456789874563',3);");
        this->base.exec("insert into Patient values(4,'Michel','148569875698541',3);");

        this->base.exec("insert into Prescription values(1,3,'2013-10-10',1,2,1);");
        this->base.exec("insert into Prescription values(2,6,'2013-10-17',2,2,2);");
        this->base.exec("insert into Prescription values(3,3,'2013-10-22',2,1,3);");
        this->base.exec("insert into Prescription values(4,6,'2013-10-26',1,2,4);");

        this->base.exec("insert into Parametres values('05000','Gap',6,3);");
     this->base.exec("commit;"); //fin transaction
    }

}
void MainWindow::fermeBase()
{
    //methode qui met fin a la connexion a la base
    this->base.close();
}

void MainWindow::on_tabWidgetMain_currentChanged(int index)// Si on change d onglet ,on recharge l onglet approprié
{
    if(index==0)
    {
    chargerPrescription();
    }
    if(index==1)
    {
       indexComboRecherchePres=-1;// on initialise cette valeur a -1 et on remet la combo box a 0 (on ne peut pas le faire dans la méthode )
    ui->comboBoxRecherchePres->setCurrentIndex(0);
     chargerListePrescription();
    }
    if(index==2)
    {
      ui->comboBoxRecherchePat->setCurrentIndex(0);//on remet la combo box a 0 et et nétoie la line edit de recherche
     ui->lineEditRecherchePat->clear();
    chargeListePatients();
    }
    if(index==3)
    {
     ui->comboBoxRechercheMed->setCurrentIndex(0);;//on remet la combo box a 0 et et nétoie la line edit de recherche
    ui->lineEditRechercheMed->clear();
    chargerListeMedecin();
    }
    if(index==4)
    {
     chargerParametres();
    }
}
//-------------------------DEBUT DE L ONGLET A RENOUVELER ---------------------
void MainWindow::clearAll()
{
    // Methode qui clean tout les elements de l'onglet avant de remplir l'onglet
    ui->listWidgetPrescriptionsARenouveler->clear();
    ui->labelARenouvelerPatient->clear();
  ui->labelARenouvelerMedAd1->clear();
    ui->labelARenouvelerMedAd2->clear();
    ui->labelARenouvelerMedCPVille->clear();
    ui->labelARenouvelerMedNumNom->clear();
     ui->labelARenouvelerMedTel->clear();
     ui->labelARenouvelerPresDateFin->clear();
  ui->labelARenouvelerPresDuree->clear();
   ui->labelARenouvelerPresModeR->clear();
    ui->labelARenouvelerPresType->clear();
    ui->labelARenouvelerMedVille->clear();
//on clear les differents vecteurs quand on (re)chage la page
    this->vectorIdPatient.clear();
     this->vectorIdPrescritption.clear();


}

void MainWindow::chargerPrescription() //méthode qui débute la construction de l'onglet
{
     clearAll(); // on nétoie tout quand on (re)charge l'onglet

     ui->dateEditARenouvelerPresDateFin->setDate(QDate(2000,01,1));//on initialise la date de renouvellement et on grise les élement tant quand q'on a pas choisi de prescription
     ui->pushButtonARenouvelerRenouveler->setDisabled(true);
     ui->dateEditARenouvelerPresDateFin->setDisabled(true);
    QSqlQuery req;
    if (req.exec("select * from Prescription natural join Patient where date('now','+15 day')>=presDate order by presDate ")) // on recherche toute les precriptions qui se finissent dans les 15 jours
    {
        while(req.next())//tant qu'il y a des prescriptions
        {
                       QSqlQuery getDays=this->base.exec("SELECT julianday('"+req.value(2).toString()+"') - julianday('now')"); //on recupere la difference de jours entre la date de fin et la date actuelle
                       if(getDays.first())
                       {

                            int nbJ = getDays.value(0).toInt(); // recupere le nombre de jours de difference
                            //on cree un nouvel item auquel on attribue un texte avec le nom la data et la difference de jours de la prescription
                            QListWidgetItem* pItem =new QListWidgetItem(req.value(6).toString()+" | Date de fin : "+req.value(2).toString()+" | "+QString::number(nbJ)+" "+jours(nbJ));
                            getColor(pItem,nbJ); // on attribue une couleur a cet item en fonction du nombre de jours de difference
                            ui->listWidgetPrescriptionsARenouveler->addItem(pItem); //enfin on ajoute l'item a la liste

                              this->vectorIdPatient.push_back(req.value(5).toInt());// on ajoute un patient dans le vecteur patient
                              this->vectorIdPrescritption.push_back(req.value(0).toInt()); //on ajoute un patient dans le vecteur presciption
                        }
        }
    }


}
void MainWindow::getColor(QListWidgetItem* monItem, int n) // méthode qui ajoute un couleur a un item en fonction du nombre de jour de difference
{
    if(n<0) // si la date est déja passé
    {

    monItem->setBackground(QBrush(QColor(250,10,10))); // on met le fond en rouge

    }
    if(n>=0 && n<=5)//s il reste 5 jours ou moins
    {
    monItem->setForeground(Qt::red); //on met l ecriture en rouge
    }
    if(n>5 && n<=10)//entre 10 et 5 jours
    {
    monItem->setForeground(QBrush(QColor(255,110,20)));// en orange
    }
    if(n>10) // entre 15 et 10 jours
    {
        monItem->setForeground(Qt::green); //en vert
    }
}


void MainWindow::on_listWidgetPrescriptionsARenouveler_currentRowChanged(int) //quand on selectionne un item
{
    // on recupere les infos de la prescirption et du client en question (on aurait pu le faire en 1 seule requete
     QSqlQuery res=this->base.exec("select * from Patient inner join Medecin on patDoc=docNum where patNum="+QString::number(this->vectorIdPatient.value(ui->listWidgetPrescriptionsARenouveler->currentIndex().row()))+";");

     if (res.first())
     {
                                                                         // on remplit les informations de l onglet liées au patient
         ui->labelARenouvelerPatient->setText("Mr/Mme : "+res.value(1).toString());
         ui->labelARenouvelerMedAd1->setText(res.value(7).toString());
        ui->labelARenouvelerMedAd2->setText(res.value(8).toString());
        ui->labelARenouvelerMedCPVille->setText(res.value(9).toString());
        ui->labelARenouvelerMedNumNom->setText(res.value(5).toString());
        ui->labelARenouvelerMedTel->setText(res.value(11).toString());
        ui->labelARenouvelerMedVille->setText(res.value(10).toString());

     }
     // les infos liées a la prescription
     QSqlQuery res2=this->base.exec("select * from Prescription where presNum="+QString::number(this->vectorIdPrescritption.value(ui->listWidgetPrescriptionsARenouveler->currentIndex().row()))+";");

     if (res2.first())
     {
         //affichage dans l'interface
         ui->labelARenouvelerPresDateFin->setText(res2.value(2).toString());
     ui->labelARenouvelerPresDuree->setText(res2.value(1).toString()+" mois");

      ui->labelARenouvelerPresModeR->setText("Medecin");  //1 => Patient et 2 => Medecin
      if(res2.value(4).toString()=="1") ui->labelARenouvelerPresModeR->setText("Patient");

       ui->labelARenouvelerPresType->setText("Precription");    //1 => DSI et 2 => Prescription
      if(res2.value(5).toString()=="1") ui->labelARenouvelerPresType->setText("DSI");
         //ui->pushButtonSupprimer->setEnabled(true);
        // ui->pushButtonModifier->setEnabled(true);
      QDate laDate = res2.value(2).toDate();
      laDate=laDate.addMonths(res2.value(1).toInt());
        ui->dateEditARenouvelerPresDateFin->setDate(laDate);// on affiche la date majoree du temps de renouvellement de la prescription
        ui->pushButtonARenouvelerRenouveler->setEnabled(true); // on permet le renouvellement
        ui->dateEditARenouvelerPresDateFin->setEnabled(true);
        }
 }



void MainWindow::on_pushButtonARenouvelerRenouveler_clicked() // quand on clique sur renouveler
{

    // on ne peut pas concaténer un date et un QString et la date.toString revoie "mar 5 sept 2013" qui ne correspond pas au champ date de la base
  //on passe par un QVariant
    QVariant date=ui->dateEditARenouvelerPresDateFin->date();
                                                                    // on update la date a la date du qtimeEdit ou le presNum
       QSqlQuery maReq2=this->base.exec("update Prescription set presDate='"+date.toString()+"' where presNum="+QString::number(this->vectorIdPrescritption.value(ui->listWidgetPrescriptionsARenouveler->currentIndex().row())));
            // on met la date de fin de la prescription a la date du dateEdit

        chargerPrescription();

}
QString MainWindow::jours(int n) // petite methode qui gere l'affichage des jours -- pluriel ou non
{
    if(n==0 or n==1 or n==-1)
    {
        return "jour";

    }
    return "jours";
}
//-------------------------------FIN DE L ONGLET A RENOUVELER ----------------------------------

//--------------------------------DEBUT DE L ONGLET PRESCRIPTIONS ------------------------------
void MainWindow::chargerListePrescription() // on charge toutes les prescription dans la liste
{

    // on nettoie et initialise tout avant !
    ui->listWidgetPrescriptions->clear();
    ui->comboBoxPrescriptionPatient->clear();
    ui->spinBoxPrescriptionDuree->setValue(0);
    ui->radioButtonDSI->setChecked(true);
    ui->radioButtonPatient->setChecked(true);
    ui->pushButtonPrescriptionSupprimer->setEnabled(false);
    ui->pushButtonPrescriptionModifier->setEnabled(false);
    ui->pushButtonPrescriptionAjouter->setEnabled(false);
    ui->pushButtonPrescriptionAbandonner->setEnabled(false);
    presChoisie=false;
    this->vectorId.clear();
    gererAffichageRecherche();// selon le critere de recherche , on affiche les bon éléments

    setDuree();// on recupere les durées par defaut des Dsi ou ordonnance selon filtre éventuels
    QSqlQuery req;
   // on recupere toutes les prescriptions avec eventuellement un filtre
    int nbLigne=0;
    if (req.exec("select presNum,patNom,presDate from Prescription natural join Patient "+AjoutRecherchePres()))
    {
        while(req.next())// tant qu il y a des prescriptions
        {
            //on ajoute un item avec le nom du patient , la date de fin ,et le numero de la prescription (ca peut etre utile)
            ui->listWidgetPrescriptions->addItem(req.value(0).toString()+" | "+req.value(1).toString()+" | Date de fin : "+req.value(2).toDate().toString());// on ajoute la prescrption dans la liste
            vectorId.push_back(req.value(0).toInt());// on ajoute le num dans le vecteur associé
            nbLigne++;
        }
    }
    if(nbLigne==0)// si il n y a pas de prescrption
    {
         ui->listWidgetPrescriptions->addItem("Pas de prescriptions correspondantes");// on le dit
    }
    chargeListePresPatient();// on charge la liste des patients
    ui->dateEditPrescriptionDateDebut->setDate(QDate::currentDate());// on initialise la date de debut a la date du jour
}
void MainWindow::on_lineEditRecherchePres_cursorPositionChanged(int , int ) // si on fait une recherche
{
    chargerListePrescription(); // on rechage la liste selon le critere voulu
}
void MainWindow::on_dateEditRecherchePres_editingFinished()// si on fait une recherche
{
    chargerListePrescription(); // on rechage la liste selon le critere voulu
}
void MainWindow::on_radioButtonRechercheChoix2_clicked()// si on fait une recherche
{
     chargerListePrescription(); // on rechage la liste selon le critere voulu
}

void MainWindow::on_radioButtonRechercheChoix1_clicked()// si on fait une recherche
{
     chargerListePrescription(); // on rechage la liste selon le critere voulu
}

void MainWindow::on_spinBoxRecherchePres_valueChanged(int )// si on fait une recherche
{
    chargerListePrescription(); // on rechage la liste selon le critere voulu
}
void MainWindow::gererAffichageRecherche() // methode qui gere l affiche des element a afficher selon le critere de recherche
{
    if(indexComboRecherchePres<1) // si on ne fait pas de recherche
    {
        ui->spinBoxRecherchePres->setVisible(false); // on cache tout
        ui->dateEditRecherchePres->setVisible(false);
        ui->radioButtonRechercheChoix1->setVisible(false);
        ui->radioButtonRechercheChoix2->setVisible(false);
       ui->lineEditRecherchePres->setVisible(false);
       ui->labelMoisRecherchePres->setVisible(false);

    }
    if(indexComboRecherchePres==1 or indexComboRecherchePres==2) //recherche pas num ou par nom
    {
        ui->spinBoxRecherchePres->setVisible(false);
        ui->dateEditRecherchePres->setVisible(false);
        ui->radioButtonRechercheChoix1->setVisible(false);
        ui->radioButtonRechercheChoix2->setVisible(false);
       ui->lineEditRecherchePres->setVisible(true); // on cache tout sauf la line edit
       ui->labelMoisRecherchePres->setVisible(false);
    }
    if(indexComboRecherchePres==3) // recherche par date de fin
    {
        ui->spinBoxRecherchePres->setVisible(false);
        ui->dateEditRecherchePres->setVisible(true); // on cache tout sauf la date edit
        ui->radioButtonRechercheChoix1->setVisible(false);
        ui->radioButtonRechercheChoix2->setVisible(false);
       ui->lineEditRecherchePres->setVisible(false);
       ui->labelMoisRecherchePres->setVisible(false);
    }
    if(indexComboRecherchePres==4) // recherche pas duree
    {
        ui->spinBoxRecherchePres->setVisible(true); // on cache tout sauf la spin box
        ui->labelMoisRecherchePres->setVisible(true); // on ajout "mois" apres la spin box
        ui->dateEditRecherchePres->setVisible(false);
        ui->radioButtonRechercheChoix1->setVisible(false);
        ui->radioButtonRechercheChoix2->setVisible(false);
       ui->lineEditRecherchePres->setVisible(false);
    }
    if(indexComboRecherchePres==5) // par type
    {

        ui->radioButtonRechercheChoix1->setText("DSI"); // on met dsi et ordonnance dans les choix de bouttons radios et on les affiche (on cahce tout le reste)
        ui->radioButtonRechercheChoix2->setText("Patient");
        ui->spinBoxRecherchePres->setVisible(false);
        ui->labelMoisRecherchePres->setVisible(false);
        ui->dateEditRecherchePres->setVisible(false);
        ui->radioButtonRechercheChoix1->setVisible(true);
        ui->radioButtonRechercheChoix2->setVisible(true);
       ui->lineEditRecherchePres->setVisible(false);
    }
    if(indexComboRecherchePres==6)
    {

        ui->radioButtonRechercheChoix1->setText("Patient"); // on met patient et medecin dans les choix de bouttons radios et on les affiche (on cahce tout le reste)
        ui->radioButtonRechercheChoix2->setText("Medecin");
        ui->spinBoxRecherchePres->setVisible(false);
        ui->labelMoisRecherchePres->setVisible(false);
        ui->dateEditRecherchePres->setVisible(false);
        ui->radioButtonRechercheChoix1->setVisible(true);
        ui->radioButtonRechercheChoix2->setVisible(true);
       ui->lineEditRecherchePres->setVisible(false);
    }
}

void MainWindow::on_comboBoxRecherchePres_currentIndexChanged(int index) // si on chage le critere de recherche
{
    indexComboRecherchePres=index;// on actualise l index
    gererAffichageRecherche(); // on affiche ce qu il faut
    if(index==0) // si il n y a pas de recherche
    {
           chargerListePrescription();// on réinitialise la page
    }

}
QString MainWindow::AjoutRecherchePres() // méthode qui revoit la suite d un requette selon le critere de recherche
{

    if(ui->comboBoxRecherchePres->currentIndex()==1) //par num
    {

        return "where presNum like '"+ui->lineEditRecherchePres->text()+"%'";
    }
    if(ui->comboBoxRecherchePres->currentIndex()==2) //selon le patient
    {
        QSqlQuery req("select patNum from Patient where patNom like '"+ui->lineEditRecherchePres->text()+"%'"); // on recherche tout les patient selon la line edit

        QString toReturn=" where patNum=-1"; // initalisation (la requtte ne renverra rien si on ne touve pas de patient correspondant)
        int nbPassage=0;
        while(req.next()) // tant qu il ya des résultats
        {
            if(nbPassage==0)
            {
                toReturn="where patNum ="+req.value(0).toString(); // on les ajoutes a la requette
            }
            else
            {
                toReturn+=" or patNum="+req.value(0).toString(); // on les ajoutes a la requette
            }
            nbPassage++;
        }
        return toReturn;
    }
    if(ui->comboBoxRecherchePres->currentIndex()==3)// par date de fin
    {
        QVariant date=ui->dateEditRecherchePres->date();
        return "where presDate='"+date.toString()+"'";
    }

    if(ui->comboBoxRecherchePres->currentIndex()==4) // par duree
    {
          return "where presDuree="+ui->spinBoxRecherchePres->text();
    }
    if(ui->comboBoxRecherchePres->currentIndex()==5) // par type
    {
        return "where presType="+QString::number(gererBoutonRadioRecherche());
    }
    if(ui->comboBoxRecherchePres->currentIndex()==6) // par mode de renouvellement
    {
        return "where presModeRenouv="+QString::number(gererBoutonRadioRecherche());
    }
    else
    {
               return "";
    }

}

int MainWindow::gererBoutonRadioRecherche() // methode qui permet de savoir quel bouton radio de recherche est activé
{
    if(ui->radioButtonRechercheChoix1->isChecked())
    {
         return 1;

    }
    return 2;

}
void MainWindow::chargeListePresPatient()//chargement de la comboBox des patients
{
    ui->comboBoxPrescriptionPatient->clear();// on initialise tout
    this->vectorIdPres.clear();

    //ajout "patient" par défaut
    ui->comboBoxPrescriptionPatient->addItem("Choisir un patient...");// valeur de début (indice 0)
    this->vectorIdPres.push_back(-1);


    QSqlQuery res=this->base.exec("select * from Patient order by patNom , patNumSS");// on veut tout les patients par nom
   while(res.next())
        {
        ui->comboBoxPrescriptionPatient->addItem(res.value(1).toString());// on les ajoute dans la liste
        this->vectorIdPres.push_back(res.value(0).toInt());
         }



}

void MainWindow::on_listWidgetPrescriptions_clicked(const QModelIndex &) // quand on choisi une prescription
{
    ui->pushButtonPrescriptionSupprimer->setEnabled(true);// on peut abandonner et supprimer

    ui->pushButtonPrescriptionAbandonner->setEnabled(true);
    presChoisie=true;// on a choisi une prescription (variable utile pour la gestion du boutton modifier)
    //  on recupere les infos selon la presciption choisie
    QSqlQuery res=this->base.exec("select * from  Prescription natural join Patient where presNum="+QString::number(vectorId.value(ui->listWidgetPrescriptions->currentRow())));
    if(res.first())
    {
        QDate maDate=res.value(2).toDate(); // on recupere la date de fin
    // on rempli les champs et les variables utiles aux coparaisons ulterieure
    ui->dateEditPrescriptionDateDebut->setDate(maDate.addMonths(-(res.value(1).toInt())));datePres=ui->dateEditPrescriptionDateDebut->text(); // on soustrait le duree a la date de fin afin da voir la date de début
    ui->spinBoxPrescriptionDuree->setValue(res.value(1).toInt());dureePres=res.value(1).toInt();
    ui->comboBoxPrescriptionPatient->setCurrentIndex(this->vectorIdPres.lastIndexOf(res.value(5).toInt()));presPatient=ui->comboBoxPrescriptionPatient->currentText();
    setButtonPres(res.value(3).toInt(),res.value(4).toInt()); // on coche les button radio corespondant (DSI/ORDO, PAT/MED)
    patOrMed=res.value(3).toInt();
    dsiOrOrdo=res.value(4).toInt();// fin d enregistrement des parametres a comparer
    ui->pushButtonPrescriptionModifier->setEnabled(false);

    ui->pushButtonPrescriptionAjouter->setEnabled(false);// on ne peut ni ajouter ni modifier si il ny a pas de changement
    }
}
void MainWindow::setButtonPres(int n1, int n2) // methode qui coche les boutton radio selon les valeurs passée en parametres
{
    if(n1==1) // si c est u patient
    {
        ui->radioButtonPatient->setChecked(true);
    }
    else // un medecin
    {
        ui->radioButtonMedecin->setChecked(true);
    }
    if(n2==1) // une dsi
    {
        ui->radioButtonDSI->setChecked(true);
    }
    else // une ordonnance
    {
        ui->radioButtonOrdonnance->setChecked(true);
    }

}

int MainWindow::gererBoutonRadio() // methode qui revoit 1 si 'patient' est coché , 2 si c est 'medecin'
{
    if(ui->radioButtonPatient->isChecked())
    {
         return 1;

    }
    return 2;

}
int MainWindow::gererBoutonRadio2()// methode qui revoit 1 si 'dsi' est coché , 2 si c est 'ordonnance'
{
    if(ui->radioButtonDSI->isChecked())
    {
         return 1;

    }
    return 2;

}
bool MainWindow::nonVidePres()// methode qui revoit true si la duree est > 0 et si un patient est chosi , false sinon
{
    return(ui->comboBoxPrescriptionPatient->currentIndex()>0 and ui->spinBoxPrescriptionDuree->text().toInt()>0);
}
bool MainWindow::estDifferentPres() // methode qui renvoie true si il ya eu des changement , false sinon (en fonction des variables remplies lors du choix d'un prescriptiion)
{

    return(presPatient!=ui->comboBoxPrescriptionPatient->currentText() or dureePres!=ui->spinBoxPrescriptionDuree->text().toInt() or datePres!=ui->dateEditPrescriptionDateDebut->text() or patOrMed!=gererBoutonRadio() or dsiOrOrdo!=gererBoutonRadio2());
}
void MainWindow::gererButtonPres() // methode qui gere l activation ou non des boutton
{
    if(nonVidePres() and estDifferentPres()) // si tout les champs sont remplis et qu ils sont differents de ceux de base
    {
        if(presChoisie) // si on a choisi une prescrption
        {
        ui->pushButtonPrescriptionModifier->setEnabled(true);//on peut modifier
        }
        ui->pushButtonPrescriptionAjouter->setEnabled(true); // on peut ajouter
    }
    else // sino on grise les bouttons
    {
         if(presChoisie)
        {
        ui->pushButtonPrescriptionModifier->setEnabled(false);
        }
        ui->pushButtonPrescriptionAjouter->setEnabled(false);
    }
    if(presChoisie==false and triggerNonRadio==false) // si on a pas choisi de presciption et qu'on clique sur dsi ou ordonnance
    {
        setDuree(); // on met la bonne valeur dans la spin box duree
    }
}

void MainWindow::on_pushButtonPrescriptionAbandonner_clicked() // quand on abandonne , on recharge l onglet
{
    chargerListePrescription();
}

void MainWindow::on_pushButtonPrescriptionSupprimer_clicked() // quand on supprime
{
    // on supprime la prescription et on rechage l onglet
    QSqlQuery res=this->base.exec("delete from Prescription where presNum="+QString::number(vectorId.value(ui->listWidgetPrescriptions->currentRow())));
    chargerListePrescription();
}

void MainWindow::on_pushButtonPrescriptionAjouter_clicked() // quand on ajoute
{
      QSqlQuery req=this->base.exec("select max(presNum) from prescription ");
      QString noPres;
        if(req.first())
      {
            noPres=QString::number(req.value(0).toInt()+1); // on recupere le dernier presNum et on l incremente
        }

    QVariant date =ui->dateEditPrescriptionDateDebut->date().addMonths(ui->spinBoxPrescriptionDuree->value()); // on recupere la date dans un qvariant pour gerer le format date
    // on ajoute et on recharge l onglet
    QSqlQuery res=this->base.exec("insert into Prescription values("+noPres+","+ui->spinBoxPrescriptionDuree->text()+",'"+date.toString()+"',"+QString::number(gererBoutonRadio())+","+QString::number(gererBoutonRadio2())+","+QString::number(vectorIdPres.value(ui->comboBoxPrescriptionPatient->currentIndex()))+")");
chargerListePrescription();
}
void MainWindow::on_pushButtonPrescriptionModifier_clicked() // quand on modifie
{
    QVariant date =ui->dateEditPrescriptionDateDebut->date(); // on recupere la date avec un qVariant pour gere le format date
    qDebug()<<date.toString();
    // on modifie et on recharge l onglet
    QSqlQuery res=this->base.exec("update Prescription set presDuree="+ui->spinBoxPrescriptionDuree->text()+", presDate='"+date.toString()+"', presModeRenouv="+QString::number(gererBoutonRadio())+", presType="+QString::number(gererBoutonRadio2())+", patNum="+QString::number(vectorIdPres.value(ui->comboBoxPrescriptionPatient->currentIndex()))+" where presNum="+QString::number(vectorId.value(ui->listWidgetPrescriptions->currentRow())));
chargerListePrescription();
}

void MainWindow::on_comboBoxPrescriptionPatient_currentIndexChanged(int ) // une info été modifiée , on gere les boutton
{
    gererButtonPres();
}



void MainWindow::on_spinBoxPrescriptionDuree_valueChanged(int ) // une info été modifiée , on gere les boutton
{
    triggerNonRadio=true;
    gererButtonPres();
}

void MainWindow::on_radioButtonDSI_clicked()// une info été modifiée , on gere les boutton
{
     triggerNonRadio=false;
    gererButtonPres();
}

void MainWindow::on_radioButtonPatient_clicked()// une info été modifiée , on gere les boutton
{
     triggerNonRadio=true;
    gererButtonPres();
}

void MainWindow::on_radioButtonOrdonnance_clicked() // une info été modifiée , on gere les boutton
{
     triggerNonRadio=false;
    gererButtonPres();
}

void MainWindow::on_radioButtonMedecin_clicked()// une info été modifiée , on gere les boutton
{
     triggerNonRadio=true;
    gererButtonPres();
}

void MainWindow::on_dateEditPrescriptionDateDebut_editingFinished()// une info été modifiée , on gere les boutton
{
    gererButtonPres();
}

void MainWindow::setDuree()// méthode qui remplie la spin box avec la valeur par defeut selon si c est une dsi ou ordonncance
{
    QSqlQuery req=this->base.exec("select dureeDsi , dureeOrdonnance from Parametres");
    if(req.first())
    {

        if(gererBoutonRadio2()==1) // selon quelle radio est activé
        {
            ui->spinBoxPrescriptionDuree->setValue(req.value(0).toInt());
        }
        else
        {
            ui->spinBoxPrescriptionDuree->setValue(req.value(1).toInt());
        }
    }

}

//-------------------------------FIN DE L ONGLET PRESCRIPTION -------------------------------

//-------------------------------DEBUT DE L ONGLET PATIENTS------------------------------------------

void MainWindow::chargeListePatients() //on charge tout les patiens dans dans la liste
{
    //vidage des listes d'��tudiants
    ui->listWidgetPatients->clear(); //on clear tout a chaque chargement
    vectorIdPatients.clear(); // on clear le vecteur d Id associé
    /**************************************/
    /** chargement de la liste*************/
    /**************************************/
    //requete
    QSqlQuery req;
    int noPass=0;
    if (req.exec("select * from Patient "+AjoutRecherchePat()+" order by patNom, patNumSS;")) // on veut tout les patients triés pas leur non et leur No de sécurité sociale avec éventuellement un filtre de recherche
    {
        while(req.next())
        {
               ui->listWidgetPatients->addItem(req.value(1).toString()); // ajout des patients dans la listeWidget
               vectorIdPatients.push_back(req.value(0).toInt()); // ajout des Id dans de vecteur associé
               noPass++;
        }
        if(noPass==0)// si il n y a pas de patient ou qu'aucun de correspond a la recherche
        {
            ui->listWidgetPatients->addItem("Pas de patients correspondants");
        }
    }
    //initialisation des zones de saisie
    ui->lineEditPatientNom->clear();
    ui->lineEditPatientNumSS->clear();
    this->chargeListePatientMedecin();
    patientChoisi=false; //au début , aucun patient n'est choisi (variable utile pour la gestion du modifier)
    ui->pushButtonPatientSupprimer->setEnabled(false); // on grise tout les boutton
    ui->pushButtonPatientModifier->setEnabled(false);
    ui->pushButtonPatientAjouter->setEnabled(false);
    ui->pushButtonPatientAbandonner->setEnabled(false);

}
void MainWindow::on_lineEditRecherchePat_cursorPositionChanged(int , int )// si on fait un recherche
{
    chargeListePatients(); // on recharge la liste voulue
}

void MainWindow::on_comboBoxRecherchePat_currentIndexChanged(int index)// si on change le mode recherche
{
    if(index==0)// si on ne veut pas rechercher
    {

       ui->lineEditRecherchePat->clear();// on netoie la line edit
        chargeListePatients();// on recharge la page
        ui->lineEditRecherchePat->setEnabled(false); // on grise la line edit
    }
    else
    {
    ui->lineEditRecherchePat->setEnabled(true);// sinon on remet la line edit en Enabled
    }
}
QString MainWindow::AjoutRecherchePat()// methode qui revoi la suite de la requette en fonction du critere de recherche
{

    if(ui->comboBoxRecherchePat->currentIndex()==1) // par num
    {
        return "where patNum like '"+ui->lineEditRecherchePat->text()+"%'";
    }
    if(ui->comboBoxRecherchePat->currentIndex()==2) // par nom
    {
        return "where patNom like '"+ui->lineEditRecherchePat->text()+"%'";
    }
    if(ui->comboBoxRecherchePat->currentIndex()==3) // par noSS
    {
        return "where patNumSS like '"+ui->lineEditRecherchePat->text()+"%'";
    }
    if(ui->comboBoxRecherchePat->currentIndex()==4) // selon le medecin traitant
    {
        QSqlQuery req("select docNum,docNom from Medecin where docNom like '"+ui->lineEditRecherchePat->text()+"%'"); // on recherche tout les medecin selon la line edit

        QString toReturn=" where patDoc=-1"; // si il n y a pas de medecin on revoi une requette qui ne reverra rien
        int nbPassage=0;
        while(req.next())// tant qu il y a des medecins correspondant on les "ajoute dans la requette"
        {
            if(nbPassage==0)// au 1er passage on crée le debut de l ajout de la requette
            {
                toReturn="where patDoc ="+req.value(0).toString();
            }
            else
            {
                toReturn+=" or patDoc="+req.value(0).toString(); // ajout éventuels
            }
            nbPassage++;
        }
        return toReturn;// on revoie l ajout de la requette
    }
    else
    {
        return "";
    }
}
void MainWindow::chargeListePatientMedecin() // chargement de la comboBox des médecins des patients
{
    ui->comboBoxPatientMedecin->clear(); // on vide la liste avant chaque chargement
    this->vectorIdPatientMedecin.clear(); // de meme pour le vecteur associé

    ui->comboBoxPatientMedecin->addItem("Choisir un medecin..."); //1er terme de la combo bos
    this->vectorIdPatientMedecin.push_back(-1); //auquel on associe la valeur -1

    QSqlQuery res=this->base.exec("select docNum,docNom from Medecin"); // recupere tout les medecin

   while(res.next())
        {
        ui->comboBoxPatientMedecin->addItem(res.value(1).toString()); // ajout du nom du médecin
        this->vectorIdPatientMedecin.push_back(res.value(0).toInt()); //on lui associe son id

         }



}

void MainWindow::on_listWidgetPatients_clicked(QModelIndex )
{
    //on recupere les infos du patient choisi
    QSqlQuery res=this->base.exec("select patNom, patNumSS, patDoc from Patient inner join Medecin on patDoc=docNum where patNum="+QString::number(this->vectorIdPatients.value(ui->listWidgetPatients->currentRow())));
    if (res.first())
    {
        // on remplit l onglet avec les données du patient
        ui->lineEditPatientNom->setText(res.value(0).toString());
        ui->lineEditPatientNumSS->setText(res.value(1).toString());
        ui->pushButtonPatientSupprimer->setEnabled(true);// a ce stade on peut supprimer ou abandonner (c est tout cas il n y a pas eu de modification pour l instant)
        ui->pushButtonPatientAbandonner->setEnabled(true);

            nom=ui->lineEditPatientNom->text(); // on enregistre les valeurs en vue de les comparer + tard(et declancher ou non l'activation des bouttons modifier et ajouter)
            noSS=ui->lineEditPatientNumSS->text();
            patientChoisi=true;
            ui->pushButtonPatientAjouter->setEnabled(false);// pas de modif , on de peut pas modifier ou ajouter
            ui->pushButtonPatientModifier->setEnabled(false);
        //positionner la combo sur le bon doc
        ui->comboBoxPatientMedecin->setCurrentIndex(this->vectorIdPatientMedecin.lastIndexOf(res.value(2).toInt()));
           indexCombo=ui->comboBoxPatientMedecin->currentIndex(); // on enregistre aussi le medecin associé en vue de le comparer
    }



}



void MainWindow::on_pushButtonPatientModifier_clicked() //quand on modifie
{
    //on fait la requette on récupère directement les infos nécessaires
     QSqlQuery res=this->base.exec("UPDATE Patient set patNom ='"+ui->lineEditPatientNom->text()+"',patNumSS='"+ui->lineEditPatientNumSS->text()+"',patDoc="+QString::number(vectorIdPatientMedecin.value(ui->comboBoxPatientMedecin->currentIndex()))+" where patNum="+QString::number(vectorIdPatients.value(ui->listWidgetPatients->currentIndex().row())));
     //on recharge l onglet
     chargeListePatients();

     ui->lineEditRecherchePat->clear();
}

void MainWindow::on_pushButtonPatientAjouter_clicked() // quand on ajoute
{
     QSqlQuery req=this->base.exec("select max(patNum) from Patient");
     QString patNum;
     if (req.first())
     {
         patNum=QString::number(req.value(0).toInt()+1);// on récupere le + grand patNum et on l incremente
      }
     // on insere les données dans la base en recuperant directement les données voulues
     QSqlQuery res=this->base.exec("insert into Patient values("+patNum+",'"+ui->lineEditPatientNom->text()+"','"+ui->lineEditPatientNumSS->text()+"','"+QString::number(vectorIdPatientMedecin.value(ui->comboBoxPatientMedecin->currentIndex()))+"')");
    qDebug()<<"insert into Patient values("+patNum+",'"+ui->lineEditPatientNom->text()+"','"+ui->lineEditPatientNumSS->text()+"','"+QString::number(vectorIdPatientMedecin.value(ui->comboBoxPatientMedecin->currentIndex()))+"')";
     chargeListePatients(); // on recharge l onglet

     ui->lineEditRecherchePat->clear();
 }

void MainWindow::on_pushButtonPatientAbandonner_clicked() // abandonner => on remet tout a 0 , on recharge l onglet
{

    ui->lineEditRecherchePat->clear();
   chargeListePatients();
}

void MainWindow::on_pushButtonPatientSupprimer_clicked() //quand on supprime
{
    //on fait la requete de suppression
     QSqlQuery res=this->base.exec("delete from Patient where patNum="+QString::number(vectorIdPatients.value(ui->listWidgetPatients->currentIndex().row())));
     chargeListePatients(); // on recharge l onglet
     ui->lineEditRecherchePat->clear();
}
bool MainWindow::nonVide() // méthode qui renvoi true si tous les champs sont remplis , false sinon
{
    return (ui->lineEditPatientNom->text().length()*ui->lineEditPatientNumSS->text().length()>0 and ui->comboBoxPatientMedecin->currentIndex()!=0);

}
bool MainWindow::nonVide2() //méthode qui renvoi true si un champ est rempli , false sinon
{
    return (ui->lineEditPatientNom->text().length()+ui->lineEditPatientNumSS->text().length()>0 or ui->comboBoxPatientMedecin->currentIndex()!=0);

}

bool MainWindow::estDifferent() // méthode qui - quand on a choisi un patient - renvoie true si on a modifé qqchose , false sinon
{

    return (ui->lineEditPatientNom->text()!=nom or ui->lineEditPatientNumSS->text()!=noSS or ui->comboBoxPatientMedecin->currentIndex()!=indexCombo);

}

void MainWindow::on_lineEditPatientNom_cursorPositionChanged(int , int ) // quand on touche a une zone de saisie
{
 gereButtonPat();
}

void MainWindow::on_lineEditPatientNumSS_cursorPositionChanged(int , int ) // vois slot précedent plus haut
{
 gereButtonPat();
}
void MainWindow::on_comboBoxPatientMedecin_activated(QString ) // voir commentaires + haut
{
    gereButtonPat();
}
void MainWindow::gereButtonPat()
 {
    if(nonVide2()) // si il a au moins une valeur , on peut abandonner
    {
        ui->pushButtonPatientAbandonner->setEnabled(true);
    }
    else
    {
        ui->pushButtonPatientAbandonner->setEnabled(false);
    }
    if(nonVide() and estDifferent()) // si tout est rempli et different , on peut ajouter
    {
     ui->pushButtonPatientAjouter->setEnabled(true);
     if(patientChoisi) // et si on a choisi un item , on peut le modifier
     {
         ui->pushButtonPatientModifier->setEnabled(true);
     }

    }
    else // sinon on grise les bouttons
    {
         ui->pushButtonPatientModifier->setEnabled(false);
        ui->pushButtonPatientAjouter->setEnabled(false);
    }

}

//---------------------------------FIN DE L ONGLET PATIENTS ---------------------------------

//---------------------------------DEBUT DE L ONGLET MEDECINS --------------------------------

void MainWindow::chargerListeMedecin() //chargement des medecins dans la liste
{

    ui->listWidgetMedecins->clear();    //on clear la liste
    vectorIdMedecin.clear();    //de meme pour le vecteur d id des medecin associé
    medChoisi=false; // pas encore de medecin choisi (variable utile pour la gestion des bouttons modifier et ajouter)
    //initialisation des zones de saisie
    ui->lineEditMedecinAdr1->clear();
    ui->lineEditMedecinAdr2->clear();
    ui->lineEditMedecinCP->clear();
    ui->lineEditMedecinNom->clear();
    ui->lineEditMedecinNumSS->clear();
    ui->lineEditMedecinTel->clear();
    ui->lineEditMedecinVille->clear();
    /**************************************/
    /** chargement de la liste*************/
    /**************************************/
    //requete
    QSqlQuery req;
    int totResult=0;
    if (req.exec("select * from Medecin "+AjoutRechercheMed()+" order by docNom, docNumSS ")) // on veut tout les medecins par nom , et avec un filtre eventuel
    {
        while(req.next())
        {
               ui->listWidgetMedecins->addItem(req.value(1).toString());//on ajoute un medecin
               vectorIdMedecin.push_back(req.value(0).toInt()); // on ajoute son id dans le vecteur associé
                totResult++;
        }

    }

    if(totResult==0) // si aucun medecin ne correspond ou qu il n y a pas de medecin du tout
    {
        ui->listWidgetMedecins->addItem("Pas de medecin(s) correspondants");
    }



    QSqlQuery req2; // on recupere les valeurs pas défaut des medecins (cp + ville)
    req2.exec("select codePostal,ville from Parametres");
    if(req2.first())
    {

            ui->lineEditMedecinCP->setText(req2.value(0).toString());// on met les valeurs par defaut

            ui->lineEditMedecinVille->setText(req2.value(1).toString());
    }
    ui->pushButtonMedecinSupprimer->setEnabled(false);// on grise tout les bouttons
    ui->pushButtonMedecinModifier->setEnabled(false);
    ui->pushButtonMedecinAjouter->setEnabled(false);
    ui->pushButtonMedecinAbandonner->setEnabled(false);

}

void MainWindow::on_lineEditRechercheMed_cursorPositionChanged(int , int ) // quand on recherche un medecin
{

        chargerListeMedecin(); // on recharge la liste selon le filtre de la line edit

}
void MainWindow::on_comboBoxRechercheMed_currentIndexChanged(int index) // so on change de critere de recherche
{

    if(index==0) // si on ne veut pas de tri
    {

       ui->lineEditRechercheMed->clear();// nettoi la line edit de recherche
        chargerListeMedecin();// on recharge la liste , sans filtre
        ui->lineEditRechercheMed->setEnabled(false); // on grise la line edit
    }
    else
    {
    ui->lineEditRechercheMed->setEnabled(true); // sinon on active la line edit
    }
}
QString MainWindow::AjoutRechercheMed() // methode qui renvoi la suite de la requette au chargement
{

    if(ui->comboBoxRechercheMed->currentIndex()==1)// par num
    {
        return "where docNum like '"+ui->lineEditRechercheMed->text()+"%'";   // revoie l ajout adequat
    }
    if(ui->comboBoxRechercheMed->currentIndex()==2) // par nom
    {
        return "where docNom like '"+ui->lineEditRechercheMed->text()+"%'";
    }
   // this->base.exec("select docNum, docNom, docNumSS,docAdresse1,docAdresse2,docCP,docVille,docTel from Medecin;");

    if(ui->comboBoxRechercheMed->currentIndex()==3) // par noSS
    {
       return "where docNumSS like '"+ui->lineEditRechercheMed->text()+"%'";
    }
    if(ui->comboBoxRechercheMed->currentIndex()==4) // par adresse
    {
        return "where docAdresse1 like '"+ui->lineEditRechercheMed->text()+"%' or docAdresse2 like '"+ui->lineEditRechercheMed->text()+"%'";
    }
    if(ui->comboBoxRechercheMed->currentIndex()==5) // par cp
    {
        return "where docCP like '"+ui->lineEditRechercheMed->text()+"%'";
    }
    if(ui->comboBoxRechercheMed->currentIndex()==6) // par ville
    {
        return "where docVille like '"+ui->lineEditRechercheMed->text()+"%'";
    }
    if(ui->comboBoxRechercheMed->currentIndex()==7) // par tel
    {
        return "where docTel like '"+ui->lineEditRechercheMed->text()+"%'";
    }
    else
    {
         return "";
    }
}

void MainWindow::on_listWidgetMedecins_clicked(QModelIndex )
{
    // on recupere les infos le concernant
    QSqlQuery res=this->base.exec("select * from Medecin where docNum="+QString::number(this->vectorIdMedecin.value(ui->listWidgetMedecins->currentRow())));
    if (res.first())
    {
        //on ajoute les valeurs recues dans l onglet et on rempli les champs de base (nom , adresse..) afin de les comperer + tard
        ui->lineEditMedecinNom->setText(res.value(1).toString());nomMed=res.value(1).toString();
        ui->lineEditMedecinNumSS->setText(res.value(2).toString());noSSMed=res.value(2).toString();
        ui->lineEditMedecinAdr1->setText(res.value(3).toString());adr1=res.value(3).toString();
        ui->lineEditMedecinAdr2->setText(res.value(4).toString());adr2=res.value(4).toString();
        ui->lineEditMedecinCP->setText(res.value(5).toString());cp=res.value(5).toString();
        ui->lineEditMedecinVille->setText(res.value(6).toString());ville=res.value(6).toString();
        ui->lineEditMedecinTel->setText(res.value(7).toString());tel=res.value(7).toString();
        ui->pushButtonMedecinSupprimer->setEnabled(true);
        ui->pushButtonMedecinAbandonner->setEnabled(true);

        medChoisi=true; // on a choisi un medecin (variable utile pour la gestion du boutton modifier

            ui->pushButtonMedecinAjouter->setEnabled(false);//pas de modif , on ne peut pas modifier ou ajouter
            ui->pushButtonMedecinModifier->setEnabled(false);

    }
}
void MainWindow::gereButtonMed()
{
// comme on va faire les meme verification pour tout les slots , on crée un méthode unique , qui gere les bouttons

        if(nonVideMed2())//si on mois un champs est rempli , on peut abandonner
        {
            ui->pushButtonMedecinAbandonner->setEnabled(true);
        }
        else
        {
            ui->pushButtonMedecinAbandonner->setEnabled(false);
        }
    if(nonVideMed() and estDifferentMed())// si tout les champs sont remplis , et qu'ils sont differents de ceux choisi
    {
     ui->pushButtonMedecinAjouter->setEnabled(true); // on peut ajouter
     if(medChoisi)// si on a choisi un medecin dans la liste
     {
         ui->pushButtonMedecinModifier->setEnabled(true);// on peut le modifier
     }
    }
    else // sinon on ne peut pas modifier ou ajouter
    {
         ui->pushButtonMedecinModifier->setEnabled(false);
        ui->pushButtonMedecinAjouter->setEnabled(false);
    }
}
bool MainWindow::nonVideMed() //méthode qui renvoi true si tout les champs sont remplis , false si un champs et vide
{
    return (ui->lineEditMedecinAdr1->text().length()*ui->lineEditMedecinAdr2->text().length()*ui->lineEditMedecinCP->text().length()*ui->lineEditMedecinNom->text().length()*ui->lineEditMedecinNumSS->text().length()*ui->lineEditMedecinTel->text().length()*ui->lineEditMedecinVille->text().length()>0);
}
bool MainWindow::nonVideMed2() // méthode qui renvoi true si un champs ou plusieurs est rempli , false sinon
{
    return (ui->lineEditMedecinAdr1->text().length()+ui->lineEditMedecinAdr2->text().length()+ui->lineEditMedecinCP->text().length()+ui->lineEditMedecinNom->text().length()+ui->lineEditMedecinNumSS->text().length()+ui->lineEditMedecinTel->text().length()+ui->lineEditMedecinVille->text().length()>0);

}

bool MainWindow::estDifferentMed() // méthode qui -une fois un medecin choisi- renvoi true si il y a eu modification d'un champ au moins , false sinon
{
    return (nomMed!=ui->lineEditMedecinNom->text() or noSSMed!=ui->lineEditMedecinNumSS->text() or adr1!=ui->lineEditMedecinAdr1->text() or adr2!=ui->lineEditMedecinAdr2->text() or cp!=ui->lineEditMedecinCP->text() or ville!=ui->lineEditMedecinVille->text() or tel!=ui->lineEditMedecinTel->text());
}

void MainWindow::on_lineEditMedecinNom_cursorPositionChanged(int , int ) // il y a eu changement sur un des champs , on gere les bouttons
{
     gereButtonMed();
}

void MainWindow::on_lineEditMedecinNumSS_cursorPositionChanged(int , int )// il y a eu changement sur un des champs , on gere les bouttons
{
    gereButtonMed();
}

void MainWindow::on_lineEditMedecinAdr1_cursorPositionChanged(int , int )// il y a eu changement sur un des champs , on gere les bouttons
{
    gereButtonMed();
}

void MainWindow::on_lineEditMedecinAdr2_cursorPositionChanged(int , int )// il y a eu changement sur un des champs , on gere les bouttons
{
    gereButtonMed();
}

void MainWindow::on_lineEditMedecinCP_cursorPositionChanged(int , int )// il y a eu changement sur un des champs , on gere les bouttons
{
 gereButtonMed();
}

void MainWindow::on_lineEditMedecinVille_cursorPositionChanged(int , int )// il y a eu changement sur un des champs , on gere les bouttons
{
    gereButtonMed();
}

void MainWindow::on_lineEditMedecinTel_cursorPositionChanged(int , int )// il y a eu changement sur un des champs , on gere les bouttons
{
    gereButtonMed();
}

void MainWindow::on_pushButtonMedecinModifier_clicked() // si on modifie
{
    //requette qui modifie en recuperant directement les champs a modifier dans la requette
    QSqlQuery req=this->base.exec("update Medecin set docNom='"+ui->lineEditMedecinNom->text()+"', docNumSS='"+ui->lineEditMedecinNumSS->text()+"', docAdresse1='"+ui->lineEditMedecinAdr1->text()+"', docAdresse2='"+ui->lineEditMedecinAdr2->text()+"', docCP='"+ui->lineEditMedecinCP->text()+"', docVille='"+ui->lineEditMedecinVille->text()+"', docTel='"+ui->lineEditMedecinTel->text()+"' where docNum="+QString::number(vectorIdMedecin.value(ui->listWidgetMedecins->currentIndex().row())));
   chargerListeMedecin();// on recharge l'onglet
   ui->lineEditRechercheMed->clear();
}


void MainWindow::on_pushButtonMedecinAjouter_clicked() // quand on ajoute
{
    QSqlQuery req=this->base.exec("select max(docNum) from Medecin");
    QString docNum;
    if (req.first())
    {
        docNum=QString::number(req.value(0).toInt()+1);// on recupere le + grand num et on l incremente
     }
    // on insere les nouvelle valeurs
    QSqlQuery res=this->base.exec("insert into Medecin values("+docNum+",'"+ui->lineEditMedecinNom->text()+"','"+ui->lineEditMedecinNumSS->text()+"','"+ui->lineEditMedecinAdr1->text()+"','"+ui->lineEditMedecinAdr2->text()+"','"+ui->lineEditMedecinCP->text()+"','"+ui->lineEditMedecinVille->text()+"','"+ui->lineEditMedecinTel->text()+"')");
ui->lineEditRechercheMed->clear();
    chargerListeMedecin(); // on recharge l onglet
}

void MainWindow::on_pushButtonMedecinSupprimer_clicked() // si on supprime
{
    //on supprime le medecin dont le num est celui enregistré dans le vecteur vectorIdMedecin a l indice de l actuelle ligne selectionnée(currentRow)
    //  CE RAISONNEMENT EST VALABLE POUR TOUTE L APPLICATION , POUR TOUTES LES LISTWIDGET ET AUTRES COMBOBOX

    QSqlQuery res=this->base.exec("delete from Medecin where docNum="+QString::number(vectorIdMedecin.value(ui->listWidgetMedecins->currentIndex().row())));
    qDebug()<<"delete from Medecin where docNum="+QString::number(vectorIdMedecin.value(ui->listWidgetMedecins->currentIndex().row()));
     chargerListeMedecin();//on recharge l onglet
     //ui->lineEditRechercheMed->clear();
}

void MainWindow::on_pushButtonMedecinAbandonner_clicked()// si on abandonne
{
    ui->lineEditRechercheMed->clear();
    chargerListeMedecin();//on recharge l onglet
}
//-----------------------------FIN DE L ONGLET MEDECINS ------------------------------

//--------------------------- DEBUT DE L ONGLET PARAMETRES ----------------------------

void MainWindow::chargerParametres()// au debut de l onglet , on charge les parametres existants
{
    ui->pushButtonPrescriptionEnregistrer->setEnabled(false);
    QSqlQuery res=this->base.exec("select * from parametres");
    if(res.first())
    {
    // on remplit l onglet
    ui->lineEditParametresCPMedecin->setText(res.value(0).toString());
    ui->lineEditParametreVilleMedecin->setText(res.value(1).toString());
    ui->spinBoxParametreDureeDSI->setValue(res.value(2).toInt());
    ui->spinBoxPrescriptionDureeOdronnance->setValue(res.value(3).toInt());
    }
}
bool MainWindow::estDifferenteParam() // methode qui renvoi true si on a modifié qqchose , false sinon
{
    QSqlQuery res=this->base.exec("select * from parametres");// on recupere les infos dans la base...
    res.first();

    //et on les compare avec celle de l onglet
     return(res.value(0).toString()!=ui->lineEditParametresCPMedecin->text() or res.value(1).toString()!=ui->lineEditParametreVilleMedecin->text() or res.value(2).toString()!=ui->spinBoxParametreDureeDSI->text() or res.value(3).toString()!=ui->spinBoxPrescriptionDureeOdronnance->text());

}
bool MainWindow::nonVideParam()//verifie que la ville et le cp sont remplis et que les durées sont > 0 , revoie true si c est le cas , false sinon
{
    return(ui->lineEditParametreVilleMedecin->text().length()*ui->lineEditParametresCPMedecin->text().length()>0 and ui->spinBoxParametreDureeDSI->value()!=0 and ui->spinBoxPrescriptionDureeOdronnance->value()!=0);
}


void MainWindow::on_lineEditParametresCPMedecin_cursorPositionChanged(int , int )// il y a eu modif d'un champs , on gere les bouttons
{
    gereButtonParam();
}

void MainWindow::on_lineEditParametreVilleMedecin_cursorPositionChanged(int , int )// il y a eu modif d'un champs , on gere les bouttons
{
    gereButtonParam();
}

void MainWindow::on_spinBoxParametreDureeDSI_valueChanged(int )// il y a eu modif d'un champs , on gere les bouttons
{
    gereButtonParam();
}

void MainWindow::on_spinBoxPrescriptionDureeOdronnance_valueChanged(int )// il y a eu modif d'un champs , on gere les bouttons
{
    gereButtonParam();
}
void MainWindow::gereButtonParam() // methode qui gere le boutton de paramettre
{
    if(nonVideParam() and estDifferenteParam())//si au moins un des parametres et differents et que rien n'est vide ou =0
    {
        ui->pushButtonPrescriptionEnregistrer->setEnabled(true);// on peut modifier
    }
    else
    {
        ui->pushButtonPrescriptionEnregistrer->setEnabled(false);//sinon on ne peut pas
    }
}

void MainWindow::on_pushButtonPrescriptionEnregistrer_clicked()// si on modifie
{
       // on met a jour avec les valeurs voulues
       QSqlQuery res=this->base.exec("update Parametres set codePostal='"+ui->lineEditParametresCPMedecin->text()+"' , ville='"+ui->lineEditParametreVilleMedecin->text()+"' , dureeDsi="+ui->spinBoxParametreDureeDSI->text()+" , dureeOrdonnance="+ui->spinBoxPrescriptionDureeOdronnance->text());
       //comme visuelement , rien ne permet de dire que la modif a marchée , on affiche un message
       QMessageBox::information(this, "Bravo l'ami", "Vos modifications ont ete enregistrees");

       chargerParametres();//on recharge l onglet
}
//--------------------------------FIN DE L ONGLET PARAMETRES -----------------------------------







