/*
    SieNatJabber Project
 Language
*/
#include "setlang.h"
#ifndef _LANG_H_
#define _LANG_H_

#define LG_COPYRIGHT "Siemens natJabber Client\n(c)Kibab, Ad, Borman99\n%s r%i\nCompiled %s"

///////////////////////////////////////////////////////////////////////////////////////////
//
//    English : Недоработан!
//
///////////////////////////////////////////////////////////////////////////////////////////
#ifdef LANG_EN
#define LG_SELECT           "Select"
#define LG_BACK             "Back"
#define LG_OK               "OK"
#define LG_CLOSE            "Close"
#define LG_MENU             "Menu"
#define LG_CANCEL           "Cancel"
#define LG_EXIT             "Exit"
#define LG_HELP             "Help"
#define LG_UPDATE           "Update"
//status_schange.c
#define LG_STATUSSEL        "Status choice"
#define LG_STONLINE         "online"
#define LG_STCHAT           "chat"
#define LG_STAWAY           "away"
#define LG_STXA             "xa"
#define LG_STDND            "dnd"
#define LG_STINVIS          "invisible"
#define LG_STOFFLINE        "offline"
#define LG_STATUS           "Status"
#define LG_ENTERTEXTSTATUS  "Enter status text:"
#define LG_PRIORITY         "Priority:"
//MUC_Enter_UI.c
#define LG_NONAMECONF       "A conference name is empty!"
#define LG_ENTERMUC         "Join MUC"
#define LG_NAMEMUC          "MUC name:"
#define LG_NICK             "Nickname:"
#define LG_GETMESSAGECOUNT  "Number of messages:"
//message_list.c
#define LG_NOSENDNULLMESS   "It is impossible to send an empty message!"
#define LG_NEW              "New..."
//message_cmds.c
#define LG_SELCOMMAND       "Select command..."
#define LG_SELTEMPLATE      "Select template..."
#define LG_SELSMILE         "Select smile..."
#define LG_SELECT2          "Select..."
#define LG_CONTRESOURCES    "Resource..."  //както подругому надо
#define LG_CONTRESOURCE     "Nicknames"
#define LG_COMMANDS         "Commands"
#define LG_MSGTEMPLATE      "Templates"
#define LG_SMILE            "Smiles"
#define LG_CLOSEDLG         "Close"
//mainmenu.c
#define LG_CONTACT          "Contact"
#define LG_STATUS           "Status"
#define LG_MUC              "MUC"
#define LG_BOOKMARK         "Bookmarks"
#define LG_MVIBRA           "Vibra mode"
#define LG_MSOUND           "Sound mode"
#define LG_MOFFLINE         "Show Offline"
#define LG_PLAYER_STATUS    "Player-status"
#define LG_SETTINGS         "Settings"
#define LG_ABOUT            "About..."
#define LG_COLOR            "Colors"
#define LG_ADDCONTACT       "Add contact"
#define LG_PLAYERSTATUS     "PlayerStatus"
//main.c
#define LG_EXITSIEJC        "Exit SieJC?"
#define LG_ZLIBNOSASL       "ZLib doesn't work without SASL!"
#define LG_ENTERLOGPAS      "Enter login/password!"
#define LG_PLATFORMM        "Target platform mismatch!"
#define LG_ASTARTED         "Already started"
//jabber_util.c
#define LG_MUCEXITDONE      "Leave MUC ok"
#define LG_VERINFO          "Version Info:\nName:%s\nVersion:%s\nOS:%s"
#define LG_TIMEINFO         "Time Info:\nUTC:%s\nTime Zone:%s\n:>%s"
#define LG_LASTACTIVMSG     "IDLE: %d d. %d hr. %d min. %d sec."
//item_info.c
#define LG_ITEMIHDR         "Contact Info"
#define LG_ELROSTER         "Roster elements"
#define LG_OFFLORCONTTR     "Offline or transport contact"
#define LG_MUCPART          "MUC partcipiant"
#define LG_JTRANSP          "This contact is a transport"
#define LG_GROUPROSTER      "Roster group"
#define LG_RESOURCE         "Resource:"
#define LG_PRIORITY         "Priority:"
#define LG_REALJID          "Real JID:"
#define LG_STATUS2          "Status:"
#define LG_PRIVILEGES       "Affiliation:"
#define LG_ROLE             "Role:"
#define LG_POSIBLCLIENT     "Client features:"
#define LG_MUCSABJECT       "Sabject:"
//#define LG_MUCNICK          "Nick:"
#define LG_ISUBSCRIBE       "Subscibe:"
//history.c
#define LG_ERRORWH          "I/O Error #%u while trying to write the history"
//cont_menu.c
#define LG_MENUCONTACT      "Contact menu"
#define LG_UNKACTION        "Unknown or unsupported action!"
#define LG_ABANDON          "Leave MUC"
#define LG_MUC_ADMIN        "muc#admin"
#define LG_KIK              "Kick"
#define LG_BAN              "Ban"
#define LG_LVOISE           "Revoke voice"
#define LG_GVOISE           "Grant voice"
#define LG_PARTICIPANT      "Unaffiliate"
#define LG_MEMBER           "Grant Membership"
#define LG_MODERATOR        "Grant Moderator"
#define LG_MODERATOR_REMOVE "Remove Moderator"
#define LG_ADMIN            "Grant Admin"
#define LG_OWNER            "Grant Ownership"
#define LG_VERCLIENT        "Version"
#define LG_INFOFDISC        "Disco info"
#define LG_ON               "Connect"
#define LG_OFF              "Disconnect"
#define LG_NOSUPACTION      "No supported action"
#define LG_OHISTORY         "History"
#define LG_QUERYTIME        "Time"
#define LG_QUERYVCARD       "vCard"
#define LG_QUERYLAST        "Last Activity"
#define LG_SUBSCR           "Subscription"
#define LG_EDIT             "Edit"
#define LG_MUCCLEAR         "Clear messages"
#define LG_SUBSCRIBE        "Ask"
#define LG_SUBSCRIBED       "Allow subscription"
#define LG_UNSUBSCRIBED     "Deny subscription"
#define LG_UNSUBSCRIBE      "Remove"
#define LG_REASON           "Reason"
//clist_util.c
#define LG_AUTHORREM        "Authorization was removed!"
#define LG_AUTHORGRANTED    "Authorization was granted!"
#define LG_MUCCROK          "MUC created OK!"
//bookmarks.c
#define LG_MENUBOOKMARK     "Bookmarks menu"
//config_data.c
#define LG_NO               "No"
#define LG_YES              "Yes"
#define LG_DISABLED         "Disabled"
#define LG_ENABLED          "Enabled"
#define LG_SETUPCONECT      "Connection setup"
#define LG_LOGIN            "Login"
#define LG_PASSWORD         "Password"
#define LG_SERVER           "Server"
#define LG_HOST             "Host"
#define LG_HOSTTYPE         "Host type"
#define LG_HOSTNAME         "Host name"
#define LG_IPADRESS         "IP address"
#define LG_PORT             "Port"
#define LG_AUTHTYPE         "Auth type"
#define LG_ZLIBUSE          "ZLib usage"
#define LG_RES              "Resource"
#define LG_HISTORY          "History"
#define LG_MUCHIST          "MUC history"
#define LG_MUCDEF           "Default MUC"
#define LG_MUCDEFMSGCOUNT   "MUC message count"
#define LG_MUCDEFNIK        "Default MUC nick"
#define LG_SHOWIDLEICON     "Show icon on idle screen"
#define LG_IDLEICON         "Idle icon position"
#define LG_POPUPDIS         "Display pop-ups"
#define LG_COMPOSEV         "Composing Events"
#define LG_DELIVREP         "Delivery Report if required"

#define LG_SETUPSND         "Sounds setup"
#define LG_SNDVOL           "sndVolume"
#define LG_SNDMSGSND        "Sound Msg Send"
#define LG_SNDMSGMUC        "Sound Msg Conf"
#define LG_SNDMSGPM         "Sound Msg PM"
#define LG_SNDONLINE        "Sound for online-status"
#define LG_SNDOFFLINE       "Sound for offline-status"
#define LG_SNDCOMPOSING     "Sound for composing-events"

#define LG_SETUPPATH        "Paths setup"
#define LG_PATHHIST         "History path"
#define LG_PATHPIC          "Pictures path"
#define LG_PATHAVATARS      "Avatars path"
#define LG_PATHCMD          "Commands path"
#define LG_PATHMESG         "Messages path"
#define LG_PATHKNOWF        "Known features"
#define LG_PATHSMILECFG     "Smiles config"
#define LG_PATHSMILEDIR     "Smiles .png path"
#define LG_DEFAULTDISK      "Default disc"
#define LG_COLORPATH        "Color schemes path"

#define LG_TEXTSTATUS       "Statuses text"
#define LG_DEFSTATES        "Default states"

#define LG_VIEW             "View"
#define LG_ROSTER_FONT      "Roster font"
#define LG_CHATS_FONT       "Messagelist font"
#define LG_SMALL_NORMAL_FONT "Small"
#define LG_SMALL_BOLD_FONT  "Small bold"
#define LG_MID_NORMAL_FONT  "Medium"
#define LG_MID_BOLD_FONT    "Medium bold"
#define LG_LARGE_NORMAL_FONT "Large"
#define LG_LARGE_BOLD_FONT  "Large bold"
#define LG_UNDERLINING      "Underline messages"
#define LG_KBD_LAYOUT       "Keyboard \"layout\""
#define LG_KBD1             "Layout 1"
#define LG_KBD2             "Layout 2"
#define LG_SKROLL           "SCROLL"

#define LG_AUTOSTATUS       "Autostatus"
#define LG_AS_ENABLED       "Enable"
#define LG_AS_TIME          "Time (minutes)"
#define LG_AS_TEXT          "Text"

/*#define LG_ICONBAR_SI       "Show icon in IconBar"
#define LG_ICONSET_FILENAME "File name with icon numbers"*/ // IconBar
//vCard.c

#define LG_SHOW_AVATAR      "Show avatar"

#define LG_VCARD_JABBERID   "JID"
#define LG_VCARD_FN         "Full name"
#define LG_VCARD_NICKNAME   "Nickname"
#define LG_VCARD_N_FAMILY   "LG_VCARD_N_FAMILY"
#define LG_VCARD_N_GIVEN    "LG_VCARD_N_GIVEN"
#define LG_VCARD_N_MIDDLE   "LG_VCARD_N_MIDDLE"
#define LG_VCARD_N_PREFIX   "LG_VCARD_N_PREFIX"
#define LG_VCARD_N_SUFFIX   "LG_VCARD_N_SUFFIX"
#define LG_VCARD_BDAY       "Birthday"
#define LG_VCARD_GENDER     "Gender"
#define LG_VCARD_ORGNAME    "Org. name"
#define LG_VCARD_ORGUNIT    "Org. unit"
#define LG_VCARD_TITLE      "Title"
#define LG_VCARD_ROLE       "Role"
#define LG_VCARD_EMAIL      "E-Mail"
#define LG_VCARD_EMAIL_HOME          "EMAIL_HOME"
#define LG_VCARD_EMAIL_WORK          "EMAIL_WORK"
#define LG_VCARD_EMAIL_INTERNET      "EMAIL_INTERNET"
#define LG_VCARD_EMAIL_PREF          "EMAIL_PREF"
#define LG_VCARD_EMAIL_X400          "EMAIL_X400"

#define LG_VCARD_TEL_HOME   "LG_VCARD_TEL_HOME"
#define LG_VCARD_TEL_WORK   "LG_VCARD_TEL_WORK"
#define LG_VCARD_TEL_VOICE  "LG_VCARD_TEL_VOICE"
#define LG_VCARD_TEL_FAX    "LG_VCARD_TEL_FAX"
#define LG_VCARD_TEL_PAGER  "LG_VCARD_TEL_PAGER"
#define LG_VCARD_TEL_MSG    "LG_VCARD_TEL_MSG"
#define LG_VCARD_TEL_CELL   "LG_VCARD_TEL_CELL"
#define LG_VCARD_TEL_VIDEO  "LG_VCARD_TEL_VIDEO"
#define LG_VCARD_TEL_BBS    "LG_VCARD_TEL_BBS"
#define LG_VCARD_TEL_MODEM  "LG_VCARD_TEL_MODEM"
#define LG_VCARD_TEL_ISDN   "LG_VCARD_TEL_ISDN"
#define LG_VCARD_TEL_PCS    "LG_VCARD_TEL_PCS"
#define LG_VCARD_TEL_PREF   "LG_VCARD_TEL_PREF"
#define LG_VCARD_TEL_NUMBER "LG_VCARD_TEL_NUMBER"

#define LG_VCARD_ADR_HOME   "ADR_HOME"
#define LG_VCARD_ADR_WORK   "ADR_WORK"
#define LG_VCARD_ADR_POSTAL "ADR_POSTAL"
#define LG_VCARD_ADR_PARCEL "ADR_PARCEL"
#define LG_VCARD_ADR_DOM    "ADR_DOM"
#define LG_VCARD_ADR_PREF   "ADR_PREF"
#define LG_VCARD_ADR_POBOX  "ADR_POBOX"
#define LG_VCARD_ADR_EXTADD "ADR_EXTADD"
#define LG_VCARD_ADR_STREET "ADR_STREET"
#define LG_VCARD_ADR_LOCALITY   "ADR_LOCALITY"
#define LG_VCARD_ADR_REGION "Region(state)"
#define LG_VCARD_ADR_PCODE  "Post code"
#define LG_VCARD_ADR_CTRY   "Country"

#define LG_VCARD_URL        "Homepage"
#define LG_VCARD_DESC       "Description"
#define LG_VCARD_TZ         "Time zone"
#define LG_VCARD_AVATAR     "Avatar"
//jid_enter_ui
#define LG_JEDELCONTACT     "Delete contact:"
#define LG_JEASK            "Ask subscribe:"
#define LG_JEGROUP          "Group:"
#define LG_JENOJID          "No JID!"
#endif //EN

///////////////////////////////////////////////////////////////////////////////////////////
//
//    简体中文 : 未全部完成!
//
///////////////////////////////////////////////////////////////////////////////////////////
#ifdef LANG_ZH
#define LG_SELECT           "选择"
#define LG_BACK             "返回"
#define LG_OK               "确定"
#define LG_CLOSE            "关闭"
#define LG_MENU             "菜单"
#define LG_CANCEL           "取消"
#define LG_EXIT             "退出"
#define LG_HELP             "帮助"
#define LG_UPDATE           "更新"
//status_schange.c
#define LG_STATUSSEL        "状态选择"
#define LG_STONLINE         "在线"
#define LG_STCHAT           "空闲"
#define LG_STAWAY           "离开"
#define LG_STXA             "不可用"
#define LG_STDND            "请勿打扰"
#define LG_STINVIS          "隐身"
#define LG_STOFFLINE        "离线"
#define LG_STATUS           "状态"
#define LG_ENTERTEXTSTATUS  "输入状态文字:"
#define LG_PRIORITY         "优先级:"
//MUC_Enter_UI.c
#define LG_NONAMECONF       "聊天组名称空白!"
#define LG_ENTERMUC         "加入聊天组"
#define LG_NAMEMUC          "聊天组名称:"
#define LG_NICK             "昵称:"
#define LG_GETMESSAGECOUNT  "消息数量:"
//message_list.c
#define LG_NOSENDNULLMESS   "不能发送空白消息!"
#define LG_NEW              "新消息..."
//message_cmds.c
#define LG_SELCOMMAND       "选择命令..."
#define LG_SELTEMPLATE      "选择模板..."
#define LG_SELSMILE         "选择表情..."
#define LG_SELECT2          "选择..."
#define LG_CONTRESOURCES    "资源..."  //както подругому надо
#define LG_CONTRESOURCE     "昵称"
#define LG_COMMANDS         "命令"
#define LG_MSGTEMPLATE      "模板"
#define LG_SMILE            "表情"
#define LG_CLOSEDLG         "关闭"
//mainmenu.c
#define LG_CONTACT          "联系人"
#define LG_STATUS           "状态"
#define LG_MUC              "聊天组"
#define LG_BOOKMARK         "书签"
#define LG_MVIBRA           "震动模式"
#define LG_MSOUND           "声音模式"
#define LG_MOFFLINE         "显示离线用户"
#define LG_PLAYER_STATUS    "播放器状态"
#define LG_SETTINGS         "设置"
#define LG_ABOUT            "关于..."
#define LG_COLOR            "配色"
#define LG_ADDCONTACT       "添加联系人"
#define LG_PLAYERSTATUS     "播放器状态"
//main.c
#define LG_EXITSIEJC        "退出 SieJC?"
#define LG_ZLIBNOSASL       "ZLib doesn't work without SASL!"
#define LG_ENTERLOGPAS      "请输入用户名/密码!"
#define LG_PLATFORMM        "使用平台错误!"
#define LG_ASTARTED         "程序已经运行"
//jabber_util.c
#define LG_MUCEXITDONE      "退出聊天组成功"
#define LG_VERINFO          "Version Info:\nName:%s\nVersion:%s\nOS:%s"
#define LG_TIMEINFO         "Time Info:\nUTC:%s\nTime Zone:%s\n:>%s"
#define LG_LASTACTIVMSG     "IDLE: %d d. %d hr. %d min. %d sec."
//item_info.c
#define LG_ITEMIHDR         "联系人信息"
#define LG_ELROSTER         "联系人详细"
#define LG_OFFLORCONTTR     "离线或代理联系人"
#define LG_MUCPART          "聊天组成员"
#define LG_JTRANSP          "这个联系人是代理"
#define LG_GROUPROSTER      "联系人群组"
#define LG_RESOURCE         "资源:"
#define LG_PRIORITY         "优先级:"
#define LG_REALJID          "Real JID:"
#define LG_STATUS2          "状态:"
#define LG_PRIVILEGES       "Affiliation:"
#define LG_ROLE             "Role:"
#define LG_POSIBLCLIENT     "Client features:"
#define LG_MUCSABJECT       "Sabject:"
//#define LG_MUCNICK          "Nick:"
#define LG_ISUBSCRIBE       "描述:"
//history.c
#define LG_ERRORWH          "I/O Error #%u while trying to write the history"
//cont_menu.c
#define LG_MENUCONTACT      "联系人菜单"
#define LG_UNKACTION        "未知或不支持的操作!"
#define LG_ABANDON          "退出聊天组"
#define LG_MUC_ADMIN        "聊天组#管理员"
#define LG_KIK              "踢人"
#define LG_BAN              "禁止"
#define LG_LVOISE           "Revoke voice"
#define LG_GVOISE           "Grant voice"
#define LG_PARTICIPANT      "Unaffiliate"
#define LG_MEMBER           "Grant Membership"
#define LG_MODERATOR        "Grant Moderator"
#define LG_MODERATOR_REMOVE "Remove Moderator"
#define LG_ADMIN            "Grant Admin"
#define LG_OWNER            "Grant Ownership"
#define LG_VERCLIENT        "版本"
#define LG_INFOFDISC        "Disco info"
#define LG_ON               "连接"
#define LG_OFF              "取消连接"
#define LG_NOSUPACTION      "不支持的操作"
#define LG_OHISTORY         "历史"
#define LG_QUERYTIME        "时间"
#define LG_QUERYVCARD       "用户信息"
#define LG_QUERYLAST        "最后操作"
#define LG_SUBSCR           "授权"
#define LG_EDIT             "编辑"
#define LG_MUCCLEAR         "清除信息"
#define LG_SUBSCRIBE        "请求认证"
#define LG_SUBSCRIBED       "通过认证"
#define LG_UNSUBSCRIBED     "拒绝认证"
#define LG_UNSUBSCRIBE      "删除"
#define LG_REASON           "原因"
//clist_util.c
#define LG_AUTHORREM        "认证被移除!"
#define LG_AUTHORGRANTED    "认证已通过!"
#define LG_MUCCROK          "聊天组创建成功!"
//bookmarks.c
#define LG_MENUBOOKMARK     "书签菜单"
//config_data.c
#define LG_NO               "否"
#define LG_YES              "是"
#define LG_DISABLED         "不允许"
#define LG_ENABLED          "允许"
#define LG_SETUPCONECT      "连接配置"
#define LG_LOGIN            "登陆名"
#define LG_PASSWORD         "密码"
#define LG_SERVER           "服务"
#define LG_HOST             "主机"
#define LG_HOSTTYPE         "主机类型"
#define LG_HOSTNAME         "主机名称"
#define LG_IPADRESS         "IP地址"
#define LG_PORT             "端口"
#define LG_AUTHTYPE         "Auth类型"
#define LG_ZLIBUSE          "ZLib使用"
#define LG_RES              "资源"
#define LG_HISTORY          "历史"
#define LG_MUCHIST          "聊天组历史"
#define LG_MUCDEF           "默认聊天组"
#define LG_MUCDEFMSGCOUNT   "聊天组信息统计"
#define LG_MUCDEFNIK        "默认聊天组昵称"
#define LG_SHOWIDLEICON     "在主屏显示图标"
#define LG_IDLEICON         "主屏图标坐标"
#define LG_POPUPDIS         "显示弹出消息"
#define LG_COMPOSEV         "Composing Events"
#define LG_DELIVREP         "发送报告如果有需要"

#define LG_SETUPSND         "声音设置"
#define LG_SNDVOL           "音量"
#define LG_SNDMSGSND        "发送消息"
#define LG_SNDMSGMUC        "聊天组消息"
#define LG_SNDMSGPM         "PM消息"
#define LG_SNDONLINE        "上线"
#define LG_SNDOFFLINE       "下线"
#define LG_SNDCOMPOSING     "composing-events"

#define LG_SETUPPATH        "路径设置"
#define LG_PATHHIST         "历史路径"
#define LG_PATHPIC          "图片路径"
#define LG_PATHAVATARS      "形象图片路径"
#define LG_PATHCMD          "命令路径"
#define LG_PATHMESG         "模板路径"
#define LG_PATHKNOWF        "已知特征"
#define LG_PATHSMILECFG     "表情配置信息"
#define LG_PATHSMILEDIR     "表情.png路径"
#define LG_DEFAULTDISK      "默认disc"
#define LG_COLORPATH        "配色信息路径"

#define LG_TEXTSTATUS       "状态文字"
#define LG_DEFSTATES        "默认状态"

#define LG_VIEW             "显示"
#define LG_ROSTER_FONT      "联系人字体"
#define LG_CHATS_FONT       "消息列表字体"
#define LG_SMALL_NORMAL_FONT "小"
#define LG_SMALL_BOLD_FONT  "粗小"
#define LG_MID_NORMAL_FONT  "中"
#define LG_MID_BOLD_FONT    "粗中"
#define LG_LARGE_NORMAL_FONT "大"
#define LG_LARGE_BOLD_FONT  "粗大"
#define LG_UNDERLINING      "消息下划线"
#define LG_KBD_LAYOUT       "键盘布局"
#define LG_KBD1             "布局1"
#define LG_KBD2             "布局2"
#define LG_SKROLL           "卷起"

#define LG_AUTOSTATUS       "自动状态"
#define LG_AS_ENABLED       "使用"
#define LG_AS_TIME          "时间 (分)"
#define LG_AS_TEXT          "文字"

/*#define LG_ICONBAR_SI       "Show icon in IconBar"
#define LG_ICONSET_FILENAME "File name with icon numbers"*/ // IconBar
//vCard.c

#define LG_SHOW_AVATAR      "显示形象图片"

#define LG_VCARD_JABBERID   "JID"
#define LG_VCARD_FN         "全名"
#define LG_VCARD_NICKNAME   "昵称"
#define LG_VCARD_N_FAMILY   "LG_VCARD_N_FAMILY"
#define LG_VCARD_N_GIVEN    "LG_VCARD_N_GIVEN"
#define LG_VCARD_N_MIDDLE   "LG_VCARD_N_MIDDLE"
#define LG_VCARD_N_PREFIX   "LG_VCARD_N_PREFIX"
#define LG_VCARD_N_SUFFIX   "LG_VCARD_N_SUFFIX"
#define LG_VCARD_BDAY       "生日"
#define LG_VCARD_GENDER     "性别"
#define LG_VCARD_ORGNAME    "Org. name"
#define LG_VCARD_ORGUNIT    "Org. unit"
#define LG_VCARD_TITLE      "Title"
#define LG_VCARD_ROLE       "Role"
#define LG_VCARD_EMAIL      "E-Mail"
#define LG_VCARD_EMAIL_HOME          "EMAIL_HOME"
#define LG_VCARD_EMAIL_WORK          "EMAIL_WORK"
#define LG_VCARD_EMAIL_INTERNET      "EMAIL_INTERNET"
#define LG_VCARD_EMAIL_PREF          "EMAIL_PREF"
#define LG_VCARD_EMAIL_X400          "EMAIL_X400"

#define LG_VCARD_TEL_HOME   "LG_VCARD_TEL_HOME"
#define LG_VCARD_TEL_WORK   "LG_VCARD_TEL_WORK"
#define LG_VCARD_TEL_VOICE  "LG_VCARD_TEL_VOICE"
#define LG_VCARD_TEL_FAX    "LG_VCARD_TEL_FAX"
#define LG_VCARD_TEL_PAGER  "LG_VCARD_TEL_PAGER"
#define LG_VCARD_TEL_MSG    "LG_VCARD_TEL_MSG"
#define LG_VCARD_TEL_CELL   "LG_VCARD_TEL_CELL"
#define LG_VCARD_TEL_VIDEO  "LG_VCARD_TEL_VIDEO"
#define LG_VCARD_TEL_BBS    "LG_VCARD_TEL_BBS"
#define LG_VCARD_TEL_MODEM  "LG_VCARD_TEL_MODEM"
#define LG_VCARD_TEL_ISDN   "LG_VCARD_TEL_ISDN"
#define LG_VCARD_TEL_PCS    "LG_VCARD_TEL_PCS"
#define LG_VCARD_TEL_PREF   "LG_VCARD_TEL_PREF"
#define LG_VCARD_TEL_NUMBER "LG_VCARD_TEL_NUMBER"

#define LG_VCARD_ADR_HOME   "ADR_HOME"
#define LG_VCARD_ADR_WORK   "ADR_WORK"
#define LG_VCARD_ADR_POSTAL "ADR_POSTAL"
#define LG_VCARD_ADR_PARCEL "ADR_PARCEL"
#define LG_VCARD_ADR_DOM    "ADR_DOM"
#define LG_VCARD_ADR_PREF   "ADR_PREF"
#define LG_VCARD_ADR_POBOX  "ADR_POBOX"
#define LG_VCARD_ADR_EXTADD "ADR_EXTADD"
#define LG_VCARD_ADR_STREET "ADR_STREET"
#define LG_VCARD_ADR_LOCALITY   "ADR_LOCALITY"
#define LG_VCARD_ADR_REGION "地区(洲)"
#define LG_VCARD_ADR_PCODE  "邮编"
#define LG_VCARD_ADR_CTRY   "国家"

#define LG_VCARD_URL        "主页"
#define LG_VCARD_DESC       "描述"
#define LG_VCARD_TZ         "时区"
#define LG_VCARD_AVATAR     "形象图片"
//jid_enter_ui
#define LG_JEDELCONTACT     "删除联系人:"
#define LG_JEASK            "请求认证:"
#define LG_JEGROUP          "群组:"
#define LG_JENOJID          "无JID!"
#endif //ZH

#endif
