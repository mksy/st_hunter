/***************************************************************************
 *   Copyright (C) 2007 by Alexander S. Salieff                            *
 *   salieff@mail.ru                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _ICQKID2_CONSTANTS_H_
#define _ICQKID2_CONSTANTS_H_

#define TNETWORK_CLOSE 0
#define TNETWORK_ERR -1
#define TNETWORK_TIMEOUT -2

#define STATUS_WEBAWARE   (uint32_t)0x00010000
#define STATUS_SHOWIP     (uint32_t)0x00020000
#define STATUS_BIRTHDAY   (uint32_t)0x00080000
#define STATUS_WEBFRONT   (uint32_t)0x00200000
#define STATUS_DCDISABLED (uint32_t)0x01000000
#define STATUS_DCAUTH     (uint32_t)0x10000000
#define STATUS_DCCONT     (uint32_t)0x20000000

// This status added by me for comfort,
// there is not status for offline in protocol standard
#define STATUS_OFFLINE    (uint32_t)0x00001000

#define STATUS_ONLINE     (uint32_t)0x00000000
#define STATUS_AWAY       (uint32_t)0x00000001
#define STATUS_DND        (uint32_t)0x00000002
#define STATUS_NA         (uint32_t)0x00000004
#define STATUS_OCCUPIED   (uint32_t)0x00000010
#define STATUS_FREE4CHAT  (uint32_t)0x00000020
#define STATUS_INVISIBLE  (uint32_t)0x00000100

#define STATUS_EVIL       (uint32_t)0x00003000
#define STATUS_DEPRESSION (uint32_t)0x00004000
#define STATUS_HOME       (uint32_t)0x00005000
#define STATUS_WORK       (uint32_t)0x00006000
#define STATUS_LUNCH      (uint32_t)0x00002001

#define AUTH_DECLINED (uint8_t)0x00
#define AUTH_ACCEPTED (uint8_t)0x01

#define SSI_EDIT_OK           (uint16_t)0x0000
#define SSI_EDIT_ERR_NOTFOUND (uint16_t)0x0002
#define SSI_EDIT_ERR_EXIST    (uint16_t)0x0003

// Added by me, there isnt in standard
#define SSI_EDIT_ERR_NETWORK  (uint16_t)0x0004

#define SSI_EDIT_ERR_CANTADD  (uint16_t)0x000a
#define SSI_EDIT_ERR_LIMIT    (uint16_t)0x000c
#define SSI_EDIT_ERR_AIMLIST  (uint16_t)0x000d
#define SSI_EDIT_ERR_NEEDAUTH (uint16_t)0x000e

#define MTN_BEGIN  (uint16_t)0x0002
#define MTN_TYPED  (uint16_t)0x0001
#define MTN_FINISH (uint16_t)0x0000

#define X_STATUS_NONE      (size_t)0
#define X_STATUS_ANGRY     (size_t)1
#define X_STATUS_BATH      (size_t)2
#define X_STATUS_TIRED     (size_t)3
#define X_STATUS_PARTY     (size_t)4
#define X_STATUS_BEER      (size_t)5
#define X_STATUS_THINK     (size_t)6
#define X_STATUS_EAT       (size_t)7
#define X_STATUS_TV        (size_t)8
#define X_STATUS_MEET      (size_t)9
#define X_STATUS_COFFEE    (size_t)10
#define X_STATUS_MUSIC     (size_t)11
#define X_STATUS_BUSINESS  (size_t)12
#define X_STATUS_SHOOT     (size_t)13
#define X_STATUS_FUN       (size_t)14
#define X_STATUS_PHONE     (size_t)15
#define X_STATUS_GAME      (size_t)16
#define X_STATUS_STUDY     (size_t)17
#define X_STATUS_SHOP      (size_t)18
#define X_STATUS_SICK      (size_t)19
#define X_STATUS_SLEEP     (size_t)20
#define X_STATUS_SURFING   (size_t)21
#define X_STATUS_BROWSE    (size_t)22
#define X_STATUS_WORK      (size_t)23
#define X_STATUS_TYPE      (size_t)24
#define X_STATUS_PICNIC    (size_t)25
#define X_STATUS_COOK      (size_t)26
#define X_STATUS_SMOKE     (size_t)27
#define X_STATUS_IM_HIGH   (size_t)28
#define X_STATUS_WC        (size_t)29
#define X_STATUS_BE_NOT_BE (size_t)30
#define X_STATUS_PRO7_TV   (size_t)31
#define X_STATUS_LOVE      (size_t)32

#define X_STATUS_MAX_BOUND X_STATUS_LOVE

// INFO CONSTANTS

#define INFO_COUNTRY_UNSPECIFIED 0
#define INFO_COUNTRY_OTHER 9999
#define INFO_COUNTRY_AFGHANISTAN 93
#define INFO_COUNTRY_ALBANIA 355
#define INFO_COUNTRY_ALGERIA 213
#define INFO_COUNTRY_AMERICAN_SAMOA 684
#define INFO_COUNTRY_ANDORRA 376
#define INFO_COUNTRY_ANGOLA 244
#define INFO_COUNTRY_ANGUILLA 101
#define INFO_COUNTRY_ANTIGUA_AND_BARBUDA 102
#define INFO_COUNTRY_ANTILLES 5902
#define INFO_COUNTRY_ARGENTINA 54
#define INFO_COUNTRY_ARMENIA 374
#define INFO_COUNTRY_ARUBA 297
#define INFO_COUNTRY_ASCENSION_ISLAND 247
#define INFO_COUNTRY_AUSTRALIA 61
#define INFO_COUNTRY_AUSTRIA 43
#define INFO_COUNTRY_AZERBAIJAN 994
#define INFO_COUNTRY_BAHAMAS 103
#define INFO_COUNTRY_BAHRAIN 973
#define INFO_COUNTRY_BANGLADESH 880
#define INFO_COUNTRY_BARBADOS 104
#define INFO_COUNTRY_BARBUDA 120
#define INFO_COUNTRY_BELARUS 375
#define INFO_COUNTRY_BELGIUM 32
#define INFO_COUNTRY_BELIZE 501
#define INFO_COUNTRY_BENIN 229
#define INFO_COUNTRY_BERMUDA 105
#define INFO_COUNTRY_BHUTAN 975
#define INFO_COUNTRY_BOLIVIA 591
#define INFO_COUNTRY_BOSNIA_AND_HERZEGOVINA 387
#define INFO_COUNTRY_BOTSWANA 267
#define INFO_COUNTRY_BRAZIL 55
#define INFO_COUNTRY_BRITISH_VIRGIN_ISLANDS 106
#define INFO_COUNTRY_BRUNEI 673
#define INFO_COUNTRY_BULGARIA 359
#define INFO_COUNTRY_BURKINA_FASO 226
#define INFO_COUNTRY_BURUNDI 257
#define INFO_COUNTRY_CAMBODIA 855
#define INFO_COUNTRY_CAMEROON 237
#define INFO_COUNTRY_CANADA 107
#define INFO_COUNTRY_CANARY_ISLANDS 178
#define INFO_COUNTRY_CAPE_VERDE_ISLANDS 238
#define INFO_COUNTRY_CAYMAN_ISLANDS 108
#define INFO_COUNTRY_CENTRAL_AFRICAN_REPUBLIC 236
#define INFO_COUNTRY_CHAD 235
#define INFO_COUNTRY_CHILE 56
#define INFO_COUNTRY_CHINA 86
#define INFO_COUNTRY_CHRISTMAS_ISLAND 672
#define INFO_COUNTRY_COCOS_ISLANDS 6102
#define INFO_COUNTRY_COCOS_KEELING_ISLANDS 6101
#define INFO_COUNTRY_COLOMBIA 57
#define INFO_COUNTRY_COMOROS 2691
#define INFO_COUNTRY_CONGO 242
#define INFO_COUNTRY_CONGO_ZAIRE 243
#define INFO_COUNTRY_COOK_ISLANDS 682
#define INFO_COUNTRY_COSTA_RICA 506
#define INFO_COUNTRY_CROATIA 385
#define INFO_COUNTRY_CUBA 53
#define INFO_COUNTRY_CYPRUS 357
#define INFO_COUNTRY_CZECH_REPUBLIC 420
#define INFO_COUNTRY_DENMARK 45
#define INFO_COUNTRY_DIEGO_GARCIA 246
#define INFO_COUNTRY_DJIBOUTI 253
#define INFO_COUNTRY_DOMINICA 109
#define INFO_COUNTRY_DOMINICAN_REPUBLIC 110
#define INFO_COUNTRY_ECUADOR 593
#define INFO_COUNTRY_EGYPT 20
#define INFO_COUNTRY_EL_SALVADOR 503
#define INFO_COUNTRY_EQUATORIAL_GUINEA 240
#define INFO_COUNTRY_ERITREA 291
#define INFO_COUNTRY_ESTONIA 372
#define INFO_COUNTRY_ETHIOPIA 251
#define INFO_COUNTRY_FAEROE_ISLANDS 298
#define INFO_COUNTRY_FALKLAND_ISLANDS 500
#define INFO_COUNTRY_FIJI 679
#define INFO_COUNTRY_FINLAND 358
#define INFO_COUNTRY_FRANCE 33
#define INFO_COUNTRY_FRENCH_ANTILLES 5901
#define INFO_COUNTRY_FRENCH_GUIANA 594
#define INFO_COUNTRY_FRENCH_POLYNESIA 689
#define INFO_COUNTRY_GABON 241
#define INFO_COUNTRY_GAMBIA 220
#define INFO_COUNTRY_GEORGIA 995
#define INFO_COUNTRY_GERMANY 49
#define INFO_COUNTRY_GHANA 233
#define INFO_COUNTRY_GIBRALTAR 350
#define INFO_COUNTRY_GREECE 30
#define INFO_COUNTRY_GREENLAND 299
#define INFO_COUNTRY_GRENADA 111
#define INFO_COUNTRY_GUADELOUPE 590
#define INFO_COUNTRY_GUAM_US 671
#define INFO_COUNTRY_GUATEMALA 502
#define INFO_COUNTRY_GUINEA 224
#define INFO_COUNTRY_GUINEA_BISSAU 245
#define INFO_COUNTRY_GUYANA 592
#define INFO_COUNTRY_HAITI 509
#define INFO_COUNTRY_HONDURAS 504
#define INFO_COUNTRY_HONG_KONG 852
#define INFO_COUNTRY_HUNGARY 36
#define INFO_COUNTRY_ICELAND 354
#define INFO_COUNTRY_INDIA 91
#define INFO_COUNTRY_INDONESIA 62
#define INFO_COUNTRY_IRAN 98
#define INFO_COUNTRY_IRAQ 964
#define INFO_COUNTRY_IRELAND 353
#define INFO_COUNTRY_ISRAEL 972
#define INFO_COUNTRY_ITALY 39
#define INFO_COUNTRY_IVORY_COAST 225
#define INFO_COUNTRY_JAMAICA 112
#define INFO_COUNTRY_JAPAN 81
#define INFO_COUNTRY_JORDAN 962
#define INFO_COUNTRY_KAZAKHSTAN 705
#define INFO_COUNTRY_KENYA 254
#define INFO_COUNTRY_KIRIBATI 686
#define INFO_COUNTRY_KOREA_NORTH 850
#define INFO_COUNTRY_KOREA_SOUTH 82
#define INFO_COUNTRY_KUWAIT 965
#define INFO_COUNTRY_KYRGYZSTAN 706
#define INFO_COUNTRY_LAOS 856
#define INFO_COUNTRY_LATVIA 371
#define INFO_COUNTRY_LEBANON 961
#define INFO_COUNTRY_LESOTHO 266
#define INFO_COUNTRY_LIBERIA 231
#define INFO_COUNTRY_LIBYA 218
#define INFO_COUNTRY_LIECHTENSTEIN 4101
#define INFO_COUNTRY_LITHUANIA 370
#define INFO_COUNTRY_LUXEMBOURG 352
#define INFO_COUNTRY_MACAU 853
#define INFO_COUNTRY_MACEDONIA 389
#define INFO_COUNTRY_MADAGASCAR 261
#define INFO_COUNTRY_MALAWI 265
#define INFO_COUNTRY_MALAYSIA 60
#define INFO_COUNTRY_MALDIVES 960
#define INFO_COUNTRY_MALI 223
#define INFO_COUNTRY_MALTA 356
#define INFO_COUNTRY_MARSHALL_ISLANDS 692
#define INFO_COUNTRY_MARTINIQUE 596
#define INFO_COUNTRY_MAURITANIA 222
#define INFO_COUNTRY_MAURITIUS 230
#define INFO_COUNTRY_MAYOTTE_ISLAND 269
#define INFO_COUNTRY_MEXICO 52
#define INFO_COUNTRY_MICRONESIA 691
#define INFO_COUNTRY_MOLDOVA 373
#define INFO_COUNTRY_MONACO 377
#define INFO_COUNTRY_MONGOLIA 976
#define INFO_COUNTRY_MONTSERRAT 113
#define INFO_COUNTRY_MOROCCO 212
#define INFO_COUNTRY_MOZAMBIQUE 258
#define INFO_COUNTRY_MYANMAR 95
#define INFO_COUNTRY_NAMIBIA 264
#define INFO_COUNTRY_NAURU 674
#define INFO_COUNTRY_NEPAL 977
#define INFO_COUNTRY_NETHERLANDS 31
#define INFO_COUNTRY_NETHERLANDS_ANTILLES 599
#define INFO_COUNTRY_NEVIS 114
#define INFO_COUNTRY_NEW_CALEDONIA 687
#define INFO_COUNTRY_NEW_ZEALAND 64
#define INFO_COUNTRY_NICARAGUA 505
#define INFO_COUNTRY_NIGER 227
#define INFO_COUNTRY_NIGERIA 234
#define INFO_COUNTRY_NIUE 683
#define INFO_COUNTRY_NORFOLK_ISLAND 6722
#define INFO_COUNTRY_NORWAY 47
#define INFO_COUNTRY_OMAN 968
#define INFO_COUNTRY_PAKISTAN 92
#define INFO_COUNTRY_PALAU 680
#define INFO_COUNTRY_PANAMA 507
#define INFO_COUNTRY_PAPUA_NEW_GUINEA 675
#define INFO_COUNTRY_PARAGUAY 595
#define INFO_COUNTRY_PERU 51
#define INFO_COUNTRY_PHILIPPINES 63
#define INFO_COUNTRY_POLAND 48
#define INFO_COUNTRY_PORTUGAL 351
#define INFO_COUNTRY_PUERTO_RICO 121
#define INFO_COUNTRY_QATAR 974
#define INFO_COUNTRY_REUNION_ISLAND 262
#define INFO_COUNTRY_ROMANIA 40
#define INFO_COUNTRY_ROTA_ISLAND 6701
#define INFO_COUNTRY_RUSSIA 7
#define INFO_COUNTRY_RWANDA 250
#define INFO_COUNTRY_SAINT_HELENA 290
#define INFO_COUNTRY_SAINT_KITTS 115
#define INFO_COUNTRY_SAINT_KITTS_AND_NEVIS 1141
#define INFO_COUNTRY_SAINT_LUCIA 122
#define INFO_COUNTRY_SAINT_PIERRE_AND_MIQUELON 508
#define INFO_COUNTRY_SAINT_VINCENT_AND_THE_GRENADINES 116
#define INFO_COUNTRY_SAIPAN_ISLAND 670
#define INFO_COUNTRY_SAN_MARINO 378
#define INFO_COUNTRY_SAO_TOME_AND_PRINCIPE 239
#define INFO_COUNTRY_SAUDI_ARABIA 966
#define INFO_COUNTRY_SCOTLAND 442
#define INFO_COUNTRY_SENEGAL 221
#define INFO_COUNTRY_SEYCHELLES 248
#define INFO_COUNTRY_SIERRA_LEONE 232
#define INFO_COUNTRY_SINGAPORE 65
#define INFO_COUNTRY_SLOVAKIA 421
#define INFO_COUNTRY_SLOVENIA 386
#define INFO_COUNTRY_SOLOMON_ISLANDS 677
#define INFO_COUNTRY_SOMALIA 252
#define INFO_COUNTRY_SOUTH_AFRICA 27
#define INFO_COUNTRY_SPAIN 34
#define INFO_COUNTRY_SRI_LANKA 94
#define INFO_COUNTRY_SUDAN 249
#define INFO_COUNTRY_SURINAME 597
#define INFO_COUNTRY_SWAZILAND 268
#define INFO_COUNTRY_SWEDEN 46
#define INFO_COUNTRY_SWITZERLAND 41
#define INFO_COUNTRY_SYRIAN_ARAB_REPUBLIC 963
#define INFO_COUNTRY_TAIWAN 886
#define INFO_COUNTRY_TAJIKISTAN 708
#define INFO_COUNTRY_TANZANIA 255
#define INFO_COUNTRY_THAILAND 66
#define INFO_COUNTRY_TINIAN_ISLAND 6702
#define INFO_COUNTRY_TOGO 228
#define INFO_COUNTRY_TOKELAU 690
#define INFO_COUNTRY_TONGA 676
#define INFO_COUNTRY_TRINIDAD_AND_TOBAGO 117
#define INFO_COUNTRY_TUNISIA 216
#define INFO_COUNTRY_TURKEY 90
#define INFO_COUNTRY_TURKMENISTAN 709
#define INFO_COUNTRY_TURKS_AND_CAICOS_ISLANDS 118
#define INFO_COUNTRY_TUVALU 688
#define INFO_COUNTRY_UGANDA 256
#define INFO_COUNTRY_UKRAINE 380
#define INFO_COUNTRY_UNITED_ARAB_EMIRATES 971
#define INFO_COUNTRY_UNITED_KINGDOM 44
#define INFO_COUNTRY_URUGUAY 598
#define INFO_COUNTRY_USA 1
#define INFO_COUNTRY_UZBEKISTAN 711
#define INFO_COUNTRY_VANUATU 678
#define INFO_COUNTRY_VATICAN_CITY 379
#define INFO_COUNTRY_VENEZUELA 58
#define INFO_COUNTRY_VIETNAM 84
#define INFO_COUNTRY_VIRGIN_ISLANDS 123
#define INFO_COUNTRY_WALES 441
#define INFO_COUNTRY_WALLIS_AND_FUTUNA_ISLANDS 681
#define INFO_COUNTRY_WESTERN_SAMOA 685
#define INFO_COUNTRY_YEMEN 967
#define INFO_COUNTRY_YUGOSLAVIA 381
#define INFO_COUNTRY_YUGOSLAVIA_MONTENEGRO 382
#define INFO_COUNTRY_YUGOSLAVIA_SERBIA 3811
#define INFO_COUNTRY_ZAMBIA 260
#define INFO_COUNTRY_ZIMBABWE 263

#define INFO_GENDER_UNKNOWN 0
#define INFO_GENDER_FEMALE 1
#define INFO_GENDER_MALE 2

#define INFO_LANG_NONE 0
#define INFO_LANG_AFRIKAANS 55
#define INFO_LANG_ALBANIAN 58
#define INFO_LANG_ARABIC 1
#define INFO_LANG_ARMENIAN 59
#define INFO_LANG_AZERBAIJANI 68
#define INFO_LANG_BELORUSSIAN 72
#define INFO_LANG_BHOJPURI 2
#define INFO_LANG_BOSNIAN 56
#define INFO_LANG_BULGARIAN 3
#define INFO_LANG_BURMESE 4
#define INFO_LANG_CANTONESE 5
#define INFO_LANG_CATALAN 6
#define INFO_LANG_CHAMORRO 61
#define INFO_LANG_CHINESE 7
#define INFO_LANG_CROATIAN 8
#define INFO_LANG_CZECH 9
#define INFO_LANG_DANISH 10
#define INFO_LANG_DUTCH 11
#define INFO_LANG_ENGLISH 12
#define INFO_LANG_ESPERANTO 13
#define INFO_LANG_ESTONIAN 14
#define INFO_LANG_FARCI 15
#define INFO_LANG_FINNISH 16
#define INFO_LANG_FRENCH 17
#define INFO_LANG_GAELIC 18
#define INFO_LANG_GERMAN 19
#define INFO_LANG_GREEK 20
#define INFO_LANG_GUJARATI 70
#define INFO_LANG_HEBREW 21
#define INFO_LANG_HINDI 22
#define INFO_LANG_HUNGARIAN 23
#define INFO_LANG_ICELANDIC 24
#define INFO_LANG_INDONESIAN 25
#define INFO_LANG_ITALIAN 26
#define INFO_LANG_JAPANESE 27
#define INFO_LANG_KHMER 28
#define INFO_LANG_KOREAN 29
#define INFO_LANG_KURDISH 69
#define INFO_LANG_LAO 30
#define INFO_LANG_LATVIAN 31
#define INFO_LANG_LITHUANIAN 32
#define INFO_LANG_MACEDONIAN 65
#define INFO_LANG_MALAY 33
#define INFO_LANG_MANDARIN 63
#define INFO_LANG_MONGOLIAN 62
#define INFO_LANG_NORWEGIAN 34
#define INFO_LANG_PERSIAN 57
#define INFO_LANG_POLISH 35
#define INFO_LANG_PORTUGUESE 36
#define INFO_LANG_PUNJABI 60
#define INFO_LANG_ROMANIAN 37
#define INFO_LANG_RUSSIAN 38
#define INFO_LANG_SERBO_CROATIAN 39
#define INFO_LANG_SINDHI 66
#define INFO_LANG_SLOVAK 40
#define INFO_LANG_SLOVENIAN 41
#define INFO_LANG_SOMALI 42
#define INFO_LANG_SPANISH 43
#define INFO_LANG_SWAHILI 44
#define INFO_LANG_SWEDISH 45
#define INFO_LANG_TAGALOG 46
#define INFO_LANG_TAIWANESS 64
#define INFO_LANG_TAMIL 71
#define INFO_LANG_TATAR 47
#define INFO_LANG_THAI 48
#define INFO_LANG_TURKISH 49
#define INFO_LANG_UKRAINIAN 50
#define INFO_LANG_URDU 51
#define INFO_LANG_VIETNAMESE 52
#define INFO_LANG_WELSH 67
#define INFO_LANG_YIDDISH 53
#define INFO_LANG_YORUBA 54

#define INFO_MARITAL_UNSPECIFIED 0
#define INFO_MARITAL_SINGLE 10
#define INFO_MARITAL_CLOSE_RELATIONSHIPS 11
#define INFO_MARITAL_ENGAGED 12
#define INFO_MARITAL_MARRIED 20
#define INFO_MARITAL_DIVORCED 30
#define INFO_MARITAL_SEPARATED 31
#define INFO_MARITAL_WIDOWED 40

#define INFO_OCCUPATION_UNSPECIFIED 0
#define INFO_OCCUPATION_ACADEMIC 1
#define INFO_OCCUPATION_ADMINISTRATIVE 2
#define INFO_OCCUPATION_ART_ENTERTAINMENT 3
#define INFO_OCCUPATION_COLLEGE_STUDENT 4
#define INFO_OCCUPATION_COMPUTERS 5
#define INFO_OCCUPATION_COMMUNITY_SOCIAL 6
#define INFO_OCCUPATION_EDUCATION 7
#define INFO_OCCUPATION_ENGINEERING 8
#define INFO_OCCUPATION_FINANCIAL_SERVICES 9
#define INFO_OCCUPATION_GOVERNMENT 10
#define INFO_OCCUPATION_HIGH_SCHOOL_STUDENT 11
#define INFO_OCCUPATION_HOME 12
#define INFO_OCCUPATION_ICQ_PROVIDING_HELP 13
#define INFO_OCCUPATION_LAW 14
#define INFO_OCCUPATION_MANAGERIAL 15
#define INFO_OCCUPATION_MANUFACTURING 16
#define INFO_OCCUPATION_MEDICAL_HEALTH 17
#define INFO_OCCUPATION_MILITARY 18
#define INFO_OCCUPATION_NON_GOVERNMENT_ORGANIZATION 19
#define INFO_OCCUPATION_PROFESSIONAL 20
#define INFO_OCCUPATION_RETAIL 21
#define INFO_OCCUPATION_RETIRED 22
#define INFO_OCCUPATION_SCIENCE_RESEARCH 23
#define INFO_OCCUPATION_SPORTS 24
#define INFO_OCCUPATION_TECHNICAL 25
#define INFO_OCCUPATION_UNIVERSITY_STUDENT 26
#define INFO_OCCUPATION_WEB_BUILDING 27
#define INFO_OCCUPATION_OTHER_SERVICES 99

#define INFO_INTEREST_UNSPECIFIED 0
#define INFO_INTEREST_ART 100
#define INFO_INTEREST_CARS 101
#define INFO_INTEREST_CELEBRITY_FANS 102
#define INFO_INTEREST_COLLECTIONS 103
#define INFO_INTEREST_COMPUTERS 104
#define INFO_INTEREST_CULTURE_LITERATURE 105
#define INFO_INTEREST_FITNESS 106
#define INFO_INTEREST_GAMES 107
#define INFO_INTEREST_HOBBIES 108
#define INFO_INTEREST_ICQ_PROVIDING_HELP 109
#define INFO_INTEREST_INTERNET 110
#define INFO_INTEREST_LIFESTYLE 111
#define INFO_INTEREST_MOVIES_TV 112
#define INFO_INTEREST_MUSIC 113
#define INFO_INTEREST_OUTDOOR_ACTIVITIES 114
#define INFO_INTEREST_PARENTING 115
#define INFO_INTEREST_PETS_ANIMALS 116
#define INFO_INTEREST_RELIGION 117
#define INFO_INTEREST_SCIENCE_TECHNOLOGY 118
#define INFO_INTEREST_SKILLS 119
#define INFO_INTEREST_SPORTS 120
#define INFO_INTEREST_WEB_DESIGN 121
#define INFO_INTEREST_NATURE_AND_ENVIRONMENT 122
#define INFO_INTEREST_NEWS_MEDIA 123
#define INFO_INTEREST_GOVERNMENT 124
#define INFO_INTEREST_BUSINESS_ECONOMY 125
#define INFO_INTEREST_MYSTICS 126
#define INFO_INTEREST_TRAVEL 127
#define INFO_INTEREST_ASTRONOMY 128
#define INFO_INTEREST_SPACE 129
#define INFO_INTEREST_CLOTHING 130
#define INFO_INTEREST_PARTIES 131
#define INFO_INTEREST_WOMEN 132
#define INFO_INTEREST_SOCIAL_SCIENCE 133
#define INFO_INTEREST_60S 134
#define INFO_INTEREST_70S 135
#define INFO_INTEREST_80S 136
#define INFO_INTEREST_50S 137
#define INFO_INTEREST_FINANCE_AND_CORPORATE 138
#define INFO_INTEREST_ENTERTAINMENT 139
#define INFO_INTEREST_CONSUMER_ELECTRONICS 140
#define INFO_INTEREST_RETAIL_STORES 141
#define INFO_INTEREST_HEALTH_AND_BEAUTY 142
#define INFO_INTEREST_MEDIA 143
#define INFO_INTEREST_HOUSEHOLD_PRODUCTS 144
#define INFO_INTEREST_MAIL_ORDER_CATALOG 145
#define INFO_INTEREST_BUSINESS_SERVICES 146
#define INFO_INTEREST_AUDIO_AND_VISUAL 147
#define INFO_INTEREST_SPORTING_AND_ATHLETIC 148
#define INFO_INTEREST_PUBLISHING 149
#define INFO_INTEREST_HOME_AUTOMATION 150

#define INFO_PAST_UNSPECIFIED 0
#define INFO_PAST_ELEMENTARY_SCHOOL 300
#define INFO_PAST_HIGH_SCHOOL 301
#define INFO_PAST_COLLEGE 302
#define INFO_PAST_UNIVERSITY 303
#define INFO_PAST_MILITARY 304
#define INFO_PAST_PAST_WORK_PLACE 305
#define INFO_PAST_PAST_ORGANIZATION 306
#define INFO_PAST_OTHER 399

#define INFO_AFFIL_UNSPECIFIED 0
#define INFO_AFFIL_ALUMNI_ORG 200
#define INFO_AFFIL_CHARITY_ORG 201
#define INFO_AFFIL_CLUB_SOCIAL_ORG 202
#define INFO_AFFIL_COMMUNITY_ORG 203
#define INFO_AFFIL_CULTURAL_ORG 204
#define INFO_AFFIL_FAN_CLUBS 205
#define INFO_AFFIL_FRATERNITY_SORORITY 206
#define INFO_AFFIL_HOBBYISTS_ORG 207
#define INFO_AFFIL_INTERNATIONAL_ORG 208
#define INFO_AFFIL_NATURE_AND_ENVIRONMENT_ORG 209
#define INFO_AFFIL_PROFESSIONAL_ORG 210
#define INFO_AFFIL_SCIENTIFIC_TECHNICAL_ORG 211
#define INFO_AFFIL_SELF_IMPROVEMENT_GROUP 212
#define INFO_AFFIL_SPIRITUAL_RELIGIOUS_ORG 213
#define INFO_AFFIL_SPORTS_ORG 214
#define INFO_AFFIL_SUPPORT_ORG 215
#define INFO_AFFIL_TRADE_AND_BUSINESS_ORG 216
#define INFO_AFFIL_UNION 217
#define INFO_AFFIL_VOLUNTEER_ORG 218
#define INFO_AFFIL_OTHER 299

#define PRIV_ALL_CAN_SEE          (uint8_t)1
#define PRIV_NOBODY_CAN_SEE       (uint8_t)2
#define PRIV_VISLIST_CAN_SEE      (uint8_t)3
#define PRIV_INVISLIST_CANNOT_SEE (uint8_t)4
#define PRIV_CONTACTLIST_CAN_SEE  (uint8_t)5

#define MSG_TYPE_PLAINTEXT (uint8_t)0x01
#define MSG_TYPE_PLUGIN    (uint8_t)0x1a
#define MSG_TYPE_AUTOAWAY  (uint8_t)0xE8
#define MSG_TYPE_AUTOBUSY  (uint8_t)0xE9
#define MSG_TYPE_AUTONA    (uint8_t)0xEA
#define MSG_TYPE_AUTODND   (uint8_t)0xEB
#define MSG_TYPE_AUTOFFC   (uint8_t)0xEC

#define CONN_ERR_BAD_LOGIN    0x0004
#define CONN_ERR_BAD_PASSWORD 0x0005
#define CONN_ERR_RATE_LIMIT   0x0018

#define SIGNOFF_OTHER_LOCATION 0x0001

#endif
