#ifndef _LANGUAGE_H_
#define _LANGUAGE_H_

#define LG_COPYRIGHT     "NATICQ v2.0\nRevision %d\n(C) by Rst7/CBSIE\nKren\nKibab\nShadow\nSeklth"

//��������� ������ ���� ������ ����� ����� ����
//#define LANG_SK
//#define LANG_UA
#define LANG_EN

#ifdef LANG_SK

#define LG_ALREADY_STARTED "Aplik�cia je u� spusten�!"

#define LG_CLTITLE "Kontakty "
#define LG_CLT9INP "T9: "

#define LG_CLERROR "chyba"

#define LG_CLLOOPBACK "Loopback"
#define LG_GROUPNOTINLIST "Nie s� v zozname"
//===============================

#define LG_MENU    "Menu"
#define LG_OPTIONS "Vo�by"
#define LG_CLOSE   "Zavrie�"
#define LG_CLEAR   "<C"
#define LG_DOIT    "Ulo�i�"
#define LG_PASTESM "Vlo�i�"
//-------------
#define LG_SELECT  "Vybra�"
#define	LG_TEXT    "Text"
#define LG_BACK    "Sp�"
//--------------
#define LG_ADD      "Prida�"
#define LG_ADDCNT   "Prida� kontakt"
#define LG_ENTERUIN "Zadajte UIN:"
//--------------
#define LG_ADDREN  "Prida�/Premenova�"
#define LG_SETNICK "Nastavi� nick %u ako:" //������-�� ��� ������ ������ ��������
#define LG_SMLDESC "Smile: %u %s"           //�� ������� ������������ ��������������
#define LG_ADDSMIL "Vlo�i� smajl�ka"

//===============================

#define LG_ADDCONT "Prida� kontakt..."
#define LG_AUTHREQ   "Pros�m, autorizuj ma..."
#define LG_AUTHGRANT "Si autorizovan�"

//================================
#define LG_MNUSTATUS  "Status"
#define LG_MNUXSTATUS "X-Status"
#define LG_MNUADDCONT "Prida� kontakt"
#define LG_MNUVIBRA   "Re�im vibr�ci�"
#define LG_MNUSOUND   "Re�im zvuku"
#define LG_MNUSHOWOFF "Zobrazi� offline"
#define LG_MNUSHOWGROUP "Skupiny"
#define LG_MNUEDCFG   "Nastavenia"
#define LG_MNUDISCONNECT "Odpoji�"
#define LG_MNUPING    "Ping"
#define LG_MNUABOUT   "O Elfe..."
//--------------
#define LG_MNUQUOTE    "Citova�"
#define LG_MNUADDSML   "Vlo�i� smajl�ka"
#define LG_MNUSHINFO   "Info o kontakte"
#define LG_MNUADDREN   "Prida�/Premenova�"
#define LG_MNUSAUTHREQ "Autoriz. po�iadavok"
#define LG_MNUSAUTHGRT "Autorizova�"
#define LG_MNUOPENLOG  "Otvori� hist�riu"
#define LG_MNUCLEARCHT "Vy�isti� chat"

#define LG_MNUEDNEXTACT "�al�ie okno"
#define LG_MNUEDPREVACT "Predo�l� okno"

//================================
#define LG_CHGSTATUS "Zmeni� Status"
#define LG_CHGXSTATUS "Zmeni� X-Status"

#define LG_STONLINE "Online"
#define LG_STAWAY   "Pre�"
#define LG_STNA     "Nedostupn�"
#define LG_STDND    "Neru�i�"
#define LG_STOCCUP  "Nem�m �as"
#define LG_STFFC    "M�m vo�no"
#define LG_STINVIS  "Nevidi�e�n�"
#define LG_STDEPRESSION "Smutn�"
#define LG_STEVIL "Nem�m n�ladu"
#define LG_STHOME "Doma"
#define LG_STLUNCH "Jem"
#define LG_STWORK "V pr�ci"

//================================

#define LG_ALL_CAN_SEE          "Vidite�n� pre v�etk�ch"
#define LG_VISLIST_CAN_SEE      "Vidite�n� pre zoznam 'Vidite�n�'"
#define LG_INVISLIST_CANNOT_SEE "Vidite�n� pre v�etk�ch mimo zoznamu 'Nevidite�n�'"
#define LG_CONTACTLIST_CAN_SEE  "Vidite�n� iba pre m�j zoznam kontaktov"
#define LG_NOBODY_CAN_SEE       "Nevidite�n� pre v�etk�ch"

#define LG_ENTERNAME      "Vlo� meno"
#define LG_CHOOSEGROUP    "Vyber skupinu"
#define LG_PRIVSTATUS     "Priv�tny status"
#define LG_MANAGELIST     "Spr�va zoznamu"

//================================

#define LG_MSGILLEGMSGCON "Illegal message ENIP_SOCK_CONNECTED!"
#define LG_MSGILLEGMSGREA "Illegal message ENIP_DATA_READ"
#define LG_MSGCANTCONN    "Can't connect!"
#define LG_MSGCANTCRSC    "Can't create socket, GPRS restarted!"
#define LG_MSGHOSTNFND    "Host not found!"
#define LG_MSGVIBRADIS    "Vibr�cie vypnut�!"
#define LG_MSGVIBRAENA    "Vibr�cie zapnut�!"
#define LG_MSGSNDDIS      "Zvuky vypnut�!"
#define LG_MSGSNDENA      "Zvuky zapnut�!"
#define LG_MSGNOUINPASS   "Pros�m, nastavte UIN/Heslo!"
#define LG_MSGSMILNOTFND  "Smajl�ky nen�jden�!"

//-------------------------------- MODS LANGUAGES -------------------------------//

#define LG_ID3TAG         "Re�im Id3tag"
#define LG_INCMSG         "Popup sender"
#define LG_MNUSLION       "Re�im SLI"
#define LG_REMINDERON     "Re�im vibra prip."
#define LG_MNUPINGON      "Auto Ping"
#define LG_MNUSMARTCPU    "Re�im Main msg."
#define LG_MSGINFO        "MSG Info"
#define LG_MNUUPTIMEON    "Online time"
#define LG_AUTOANSWER     "Re�im Auto odp."
#define LG_MNUILUON       "Re�im osvetlenia"
#define LG_MNUEDCFG_MOD   "Nastavenia m�du"
#define LG_MNUQUOTE2      "Citova�... ..."
#define LG_SAVECL         "Ulo�i� CL"
/*#define LG_INCMSG         "Popup sender"
#define LG_MNUSLION       "����� SLI"
#define LG_REMINDERON     "����� Vibra rem."
#define LG_MNUPINGON      "Auto Ping"
#define LG_MNUSMARTCPU    "Main msg. mode"
#define LG_MSGINFO        "MSG Info"
#define LG_MNUUPTIMEON    "Online time"
#define LG_AUTOANSWER     "������������"
#define LG_MNUILUON       "����� Ilum."
*/


//config
#define LG_NOT_ACTION       "Bez postupu"
#define LG_SOUND            "Zvuk"
#define LG_VIBRA            "Vibra"
#define LG_INVIS            "Nevidite�n�"
#define LG_VIBRA_REM        "Vibra prip."
#define LG_CLAER_ALL_CHAT   "Vy�isti� chat"
#define LG_AUTOMSG          "Auto MSG"
#define LG_SHOW_XSTATE_TIME "Uk�za� X-Status/�as"
#define LG_CONFIG           "Nastavenia"
#define LG_CONFIG_MOD       "Nastavenia m�du"
#define LG_PING             "Ping"
#define LG_HIHE_LOCK        "Zablokova�"
#define LG_IDLE             "Idle"
#define LG_USERMENU         "Pou�. Menu" 

                                                


//=================================

#define LG_HISTIOERR "Chyba I/O  #%u"

//=================================

#define LG_GRSTATESTRING "State: %d, RXstate: %d\nRx:%db,Tx:%db\nQueue: %db\n%s\n%s"
#define LG_GRSKEYEXIT    "Koniec"
#define LG_GRSKEYCLIST   "CList"

#define LG_GRTRYLOGIN    "Try to login..."
#define LG_GRWAITFORGPRS "Waiting for GPRS up..."
#define LG_GRSENDDNR     "Send DNR..."
#define LG_GRDNRERROR    "DNR ERROR %d!"
#define LG_GRDNROK       "DNR Ok, connecting..."
#define LG_GRBADPACKET   "Bad packet"
#define LG_GRLOGINMSG    "%s"
#define LG_GRSTATUSCHNG  "SC%d: %04X"
#define LG_GRERROR       "ERR: %s"
#define LG_GRRECVMSG     "MSG%d: %s"
#define LG_GRGPRSUP      "GPRS up, wait 10 sec..."

#endif

#ifdef LANG_UA

#define LG_ALREADY_STARTED "��� ������!"

#define LG_CLTITLE "��������..."
#define LG_CLT9INP "��� T9: "

#define LG_CLERROR "�������"

#define LG_CLLOOPBACK "Loopback"
#define LG_GROUPNOTINLIST "���� � ������"
//===============================

#define LG_MENU    "����"
#define LG_OPTIONS "�����"
#define LG_CLOSE   "�������"
#define LG_CLEAR   "<C"
#define LG_DOIT    "��������"
#define LG_PASTESM "��������"
//-------------
#define LG_SELECT  "����"
#define	LG_TEXT    "�����"
#define LG_BACK    "�����"
//--------------
#define LG_ADD      "������"
#define LG_ADDCNT   "������ �������"
#define LG_ENTERUIN "������ UIN:"
//--------------
#define LG_ADDREN  "������/��'�"
#define LG_SETNICK "Set nickname of %u as:" //������-�� ��� ������ ������ ��������
#define LG_SMLDESC "Smile: %u %s"           //�� ������� ������������ ��������������
#define LG_ADDSMIL "�������� �������"

//===============================

#define LG_ADDCONT "������ �������..."
#define LG_AUTHREQ   "����������� ����..."
#define LG_AUTHGRANT "��� ������������"

//================================
#define LG_MNUSTATUS  "������"
#define LG_MNUXSTATUS "X-������"
#define LG_MNUADDCONT "������ �������"
#define LG_MNUVIBRA   "����� ����"
#define LG_MNUSOUND   "����� �����"
#define LG_MNUSHOWOFF "���. ��������"
#define LG_MNUSHOWGROUP "�����"
#define LG_MNUEDCFG   "���������"
#define LG_MNUDISCONNECT "���i����� ��'����"
#define LG_MNUPING    "�i��"
#define LG_MNUABOUT   "��� �����"
//--------------
#define LG_MNUQUOTE    "��������"
#define LG_MNUADDSML   "�������� �����"
#define LG_MNUSHINFO   "�������� ����"
#define LG_MNUADDREN   "������/��'�"
#define LG_MNUSAUTHREQ "����� �������."
#define LG_MNUSAUTHGRT "������������"
#define LG_MNUOPENLOG  "³������ ������"
#define LG_MNUCLEARCHT "�������� ���"

#define LG_MNUEDNEXTACT "��������� ���"
#define LG_MNUEDPREVACT "���������� ���"

//================================
#define LG_CHGSTATUS "������ ������"
#define LG_CHGXSTATUS "������ X-������"

#define LG_STONLINE "� �����"
#define LG_STAWAY   "³�����"
#define LG_STNA     "�����������"
#define LG_STDND    "�� ���������"
#define LG_STOCCUP  "��������"
#define LG_STFFC    "³����� ��� ����"
#define LG_STINVIS  "���������"
#define LG_STDEPRESSION "�������"
#define LG_STEVIL "����"
#define LG_STHOME "�����"
#define LG_STLUNCH "��"
#define LG_STWORK "�� �����"

//================================

#define LG_ALL_CAN_SEE          "������� ��� ���"
#define LG_VISLIST_CAN_SEE      "������� ����� ��� ������, �� ������ ����"
#define LG_INVISLIST_CANNOT_SEE "������� ��� ���, ���� ������, �� �� ������ ����"
#define LG_CONTACTLIST_CAN_SEE  "������� ����� ��� ������ ��������"
#define LG_NOBODY_CAN_SEE       "��������� ��� ���"

#define LG_ENTERNAME      "������ ��'�"
#define LG_CHOOSEGROUP    "������� �����"
#define LG_PRIVSTATUS     "��������� ������"
#define LG_MANAGELIST     "��������� �������"

//================================

#define LG_MSGILLEGMSGCON "������ ����������� ENIP_SOCK_CONNECTED!"
#define LG_MSGILLEGMSGREA "������ ����������� ENIP_DATA_READ"
#define LG_MSGCANTCONN    "��������� �����������!"
#define LG_MSGCANTCRSC    "��������� �������� �����, ���������� GPRS!"
#define LG_MSGHOSTNFND    "������ �� ��������!"
#define LG_MSGVIBRADIS    "³��� ��������!"
#define LG_MSGVIBRAENA    "³��� ��������!"
#define LG_MSGSNDDIS      "����� ��������!"
#define LG_MSGSNDENA      "����� ��������!"
#define LG_MSGNOUINPASS   "������ UIN/������!"
#define LG_MSGSMILNOTFND  "������ �� ��������!"

//=================================

#define LG_HISTIOERR "������� I/O  #%u"

//=================================
#define LG_GRSTATESTRING "State: %d, RXstate: %d\nRx: %db, Tx: %db\nQueue: %db\n%s\n%t"
#define LG_GRSKEYEXIT    "Exit"
#define LG_GRSKEYCLIST   "CList"

#define LG_GRTRYLOGIN    "Try to login..."
#define LG_GRWAITFORGPRS "Waiting for GPRS up..."
#define LG_GRSENDDNR     "Send DNR..."
#define LG_GRDNRERROR    "DNR ERROR %d!"
#define LG_GRDNROK       "DNR Ok, connecting..."
#define LG_GRBADPACKET   "Bad packet"
#define LG_GRLOGINMSG    "%s"
#define LG_GRSTATUSCHNG  "SC%d: %04X"
#define LG_GRERROR       "ERR: %s"
#define LG_GRRECVMSG     "MSG%d: %s"
#define LG_GRGPRSUP      "GPRS up, wait 10 sec..."

#endif

#ifdef LANG_EN

#define LG_ALREADY_STARTED "Already started!"

#define LG_CLTITLE "Contacts..."
#define LG_CLT9INP "T9 Key: "

#define LG_CLERROR "error"

#define LG_CLLOOPBACK "Loopback"
#define LG_GROUPNOTINLIST "Not in list"
//===============================

#define LG_MENU    "Menu"
#define LG_OPTIONS "Options"
#define LG_CLOSE   "Close"
#define LG_CLEAR   "< C"
#define LG_DOIT    "Do it!"
#define LG_PASTESM "Paste it!"
//-------------
#define LG_SELECT  "Select"
#define	LG_TEXT    "Text"
#define LG_BACK    "Back"
//--------------
#define LG_ADD      "Add!"
#define LG_ADDCNT   "Add Contact"
#define LG_ENTERUIN "Please enter uin:"
//--------------
#define LG_ADDREN  "Add/Rename"
#define LG_SETNICK "Set nickname of %u as"
#define LG_SMLDESC "Smile: %u %s"
#define LG_ADDSMIL "Add Smiles"

//===============================

#define LG_ADDCONT "Add contact..."
#define LG_AUTHREQ   "Please authorize me..."
#define LG_AUTHGRANT "You are authorized!"

//================================
#define LG_MNUSTATUS  "Status"
#define LG_MNUXSTATUS "X-Status"
#define LG_MNUADDCONT "Add Contact"
#define LG_MNUVIBRA   "Vibra mode"
#define LG_MNUSOUND   "Sound mode"
#define LG_MNUSHOWOFF "Off. contacts"
#define LG_MNUSHOWGROUP "Groups"
#define LG_MNUEDCFG   "Edit config"
#define LG_MNUDISCONNECT "Disconnect"
#define LG_MNUPING    "Ping"
#define LG_MNUABOUT   "About"
//-------------
#define LG_MNUQUOTE    "Quote"
#define LG_MNUADDSML   "Add smile"
#define LG_MNUSHINFO   "Get short info"
#define LG_MNUADDREN   "Add/rename"
#define LG_MNUSAUTHREQ "Send Auth Req"
#define LG_MNUSAUTHGRT "Send Auth Grant"
#define LG_MNUOPENLOG  "Open logfile"
#define LG_MNUCLEARCHT "Clear log"

#define LG_MNUEDNEXTACT "Next active"
#define LG_MNUEDPREVACT "Prev. active"

//================================
#define LG_CHGSTATUS "Change Status"
#define LG_CHGXSTATUS "Change X-Status"

#define LG_STONLINE "Online"
#define LG_STAWAY   "Away"
#define LG_STNA     "Not Available"
#define LG_STDND    "Do Not Disturb"
#define LG_STOCCUP  "Occupied"
#define LG_STFFC    "Free For Chat"
#define LG_STINVIS  "Invisible"
#define LG_STDEPRESSION "Depression"
#define LG_STEVIL "Evil"
#define LG_STHOME "Home"
#define LG_STLUNCH "Lunch"
#define LG_STWORK "Work"

//================================

#define LG_ALL_CAN_SEE          "Visible for all"
#define LG_VISLIST_CAN_SEE      "Visible only for list seeing"
#define LG_INVISLIST_CANNOT_SEE "Visible for all, except for list blind"
#define LG_CONTACTLIST_CAN_SEE  "Visible only for list of contacts"
#define LG_NOBODY_CAN_SEE       "Invisible for all"

#define LG_ENTERNAME      "Enter a name"
#define LG_CHOOSEGROUP    "Choose a group"
#define LG_PRIVSTATUS     "Private status"
#define LG_MANAGELIST     "Management by list"

//================================

#define LG_MSGILLEGMSGCON "Illegal message ENIP_SOCK_CONNECTED!"
#define LG_MSGILLEGMSGREA "Illegal message ENIP_DATA_READ"
#define LG_MSGCANTCONN    "Can't connect!"
#define LG_MSGCANTCRSC    "Can't create socket, GPRS restarted!"
#define LG_MSGHOSTNFND    "Host not found!"
#define LG_MSGVIBRADIS    "Vibr� disabled!"
#define LG_MSGVIBRAENA    "Vibra enabled!"
#define LG_MSGSNDDIS      "Sounds disabled!"
#define LG_MSGSNDENA      "Sounds enabled!"
#define LG_MSGNOUINPASS   "Please setup UIN/PASS!"
#define LG_MSGSMILNOTFND  "Can't find smiles!"


//-------------------------------- MODS LANGUAGES -------------------------------//

#define LG_ID3TAG         "Id3tag mode"
#define LG_INCMSG         "Popup sender"
#define LG_MNUSLION       "SLI mode"
#define LG_REMINDERON     "Vibra rem. mode"
#define LG_MNUPINGON      "Auto Ping"
#define LG_MNUSMARTCPU    "Main msg. mode"
#define LG_MSGINFO        "MSG Info"
#define LG_MNUUPTIMEON    "Online time"
#define LG_AUTOANSWER     "AutoAnswer mode"
#define LG_MNUILUON       "Illumination mode"
#define LG_MNUEDCFG_MOD   "Mod settings"
#define LG_MNUQUOTE2      "Quote"
#define LG_SAVECL         "Save CL"


//config
#define LG_NOT_ACTION       "Not action"
#define LG_SOUND            "Sound"
#define LG_VIBRA            "Vibra"
#define LG_INVIS            "Invisible"
#define LG_VIBRA_REM        "Vibra rem."
#define LG_CLAER_ALL_CHAT   "Clear chat"
#define LG_AUTOMSG          "Auto MSG"
#define LG_SHOW_XSTATE_TIME "Show X-Status/Time"
#define LG_CONFIG           "Settings"
#define LG_CONFIG_MOD       "Mod settings"
#define LG_PING             "Ping"
#define LG_HIHE_LOCK        "Lock"
#define LG_IDLE             "Idle"
#define LG_USERMENU         "User Menu" 

//=================================

#define LG_HISTIOERR "I/O Error #%u"

//=================================

#define LG_GRSTATESTRING "State: %d, RXstate: %d\nRx: %db, Tx: %db\nQueue: %db\n%s\n%t"
#define LG_GRSKEYEXIT    "Exit"
#define LG_GRSKEYCLIST   "CList"

#define LG_GRTRYLOGIN    "Try to login..."
#define LG_GRWAITFORGPRS "Waiting for GPRS up..."
#define LG_GRSENDDNR     "Send DNR..."
#define LG_GRDNRERROR    "DNR ERROR %d!"
#define LG_GRDNROK       "DNR Ok, connecting..."
#define LG_GRBADPACKET   "Bad packet"
#define LG_GRLOGINMSG    "%s"
#define LG_GRSTATUSCHNG  "SC%d: %04X"
#define LG_GRERROR       "ERR: %s"
#define LG_GRRECVMSG     "MSG%d: %s"
#define LG_GRGPRSUP      "GPRS up, wait 10 sec..."

#endif

#endif


