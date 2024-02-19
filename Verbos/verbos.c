 /*5 de indicativo simple, 5 de indicativo compuesto, 3 de subjuntivo simple, 3 de subjuntivo compuesto, imperativo en la segunda persona del singular, participio y gerundio*/
#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>

enum pronombres{YO, TU, EL, NOSOTROS, USTEDES, ELLOS, TotalPronombres};
enum tiemposSimples{PRESENTE, PRETERITO, FUTURO, COPRETERITO, POSTPRETERITO, TotalTiemposSimples};                                                             
enum tiemposCompuestos{PRESENTECOM, PRETERITOCOM, FUTUROCOM, COPRETERITOCOM, POSTPRETERITOCOM, TotalTiemposCompuestos};
enum tiemposSubjuntivosS{PRESENTESS, PRETERITOSS, FUTUROSS, TotalTiemposSubjuntivosS};
enum tiemposSubjuntivosC{PRESENTESC, PRETERITOSC, FUTUROSC, TotalTiemposSubjuntivosC};


#define LONGMAX 128

typedef char enBasePronombres[TotalPronombres*TotalTiemposSimples][LONGMAX];

char *ModoIndicativoSimple[]={"Presente", "Pret�rito", "Futuro",
                             "Copret�rito", "Postpret�rito"};
                             //Presente, Pret�rito perfecto simple , Futuro, Pret�rito imperfecto, Condicional
char *ModoIndicativoCompuesto[]={"Antepresente", "Antepret�rito", "Antefuturo",
                             "Antecopret�rito", "Antepostpret�rito"};
 /*char *ModoIndicativoCompuesto[]={"Pret�rito Perfecto Compuesto", "Pret�rito anterior", "Futuro Compuesto", "Pret�rito pluscuamperfecto", "Condicional"};*/  
char *ModoSubjuntivoSimple[]={"Subjuntivo Presente","Subjuntivo Pret�rito","Subjuntivo Futuro"};
char *ModoSubjuntivoCompuesto[]={"Subjuntivo Antepresente", "Subjuntivo Antepret�rito", "Subjuntivo Antefuturo"};
char *ModoOtros[]={"Gerundio" ,"Participio","Imperativo en la segunda persona del singular"};
                                                                        
enBasePronombres DesinenciaSimpleAR = {"o      ","as     ","a      ","amos   ","an     ","an     ",
									   "�      ","aste   ","o      ","amos   ","aron   ","aron   ",
									   "ar�    ","ar�s   ","ar�    ","aremos ","ar�n   ","ar�n   ",
									   "aba    ","abas   ","aba    ","�bamos ","aban   ","aban   ",
									   "ar�a   ","ar�as  ","ar�a   ","ar�amos","ar�an  ","ar�an  "};
enBasePronombres DesinenciaSimpleER = {"o      ","es     ","e      ","emos   ","en     ","en     ",
									   "�      ","iste   ","i�     ","imos   ","ieron  ","ieron  ",
									   "er�    ","er�s   ","er�    ","eremos ","er�n   ","er�n   ",
									   "�a     ","�as    ","�a     ","�amos  ","�an    ","�an    ",
									   "er�a   ","er�as  ","er�a   ","er�amos","er�an  ","er�an  "};									   
enBasePronombres DesinenciaSimpleIR = {"o      ","es     ","e      ","imos   ","en     ","en     ",
									   "�      ","iste   ","i�     ","imos   ","ieron  ","ieron  ",
									   "ir�    ","ir�s   ","ir�    ","iremos ","ir�n   ","ir�n   ",
									   "�a     ","�as    ","�a     ","�amos  ","�an    ","�an    ",
									   "ir�a   ","ir�as  ","ir�a   ","ir�amos","ir�an  ","ir�an  "}; 

/* ----------------------------------------------------------------------------------------------------------------------------*/
enBasePronombres DesinenciaCompuestaAR = {"ado    ","ado    ","ado    ","ado    ","ado    ","ado    ",
									      "ado    ","ado    ","ado    ","ado    ","ado    ","ado    ",
									      "ado    ","ado    ","ado    ","ado    ","ado    ","ado    ",
									      "ado    ","ado    ","ado    ","ado    ","ado    ","ado    ",
									      "ado    ","ado    ","ado    ","ado    ","ado    ","ado    "};	
enBasePronombres DesinenciaCompuestaER = {"ido    ","ido    ","ido    ","ido    ","ido    ","ido    ",
									      "ido    ","ido    ","ido    ","ido    ","ido    ","ido    ",
									      "ido    ","ido    ","ido    ","ido    ","ido    ","ido    ",
									      "ido    ","ido    ","ido    ","ido    ","ido    ","ido    ",
									      "ido    ","ido    ","ido    ","ido    ","ido    ","ido    "};	
								   
/*------------------------------------------------------------------------------------------------------------------------------*/
enBasePronombres SubjuntivoSimpleAR = {"e           ","es          ","e           ","emos        ","en          ","en          ",
									   "ara         ","aras        ","ara         ","�ramos      ","aran        ","aran        ",
									   "are         ","ares        ","are         ","�remos      ","aren        ","aren        "};						   	  
enBasePronombres SubjuntivoSimpleER = {"a           ","as          ","a           ","amos        ","an          ","an          ",
									   "iera        ","ieras       ","iera        ","i�ramos     ","ieran       ","ieran       ",
									   "iere        ","ieres       ","iere        ","i�remos     ","ieren       ","ieren       "};
enBasePronombres SubjuntivoSimpleIR = {"a           ","as          ","a           ","amos        ","an          ","an          ",
									   "iera        ","ieras       ","iera        ","i�ramos     ","ieran       ","ieran       ",
									   "iere        ","ieres       ","iere        ","i�remos     ","ieren       ","ieren       "};									  
										  					   
enBasePronombres DesinenciaOtrosAR = {"ando ","ado","a t�"};
enBasePronombres DesinenciaOtrosER = {"iendo","ido","e t�"};
enBasePronombres DesinenciaOtrosIR = {"iendo","ido","e t�"};

enBasePronombres DesinenciaSimpleBrunir= {"o      ","es     ","e      ","imos   ","en     ","en     ",
								   		  "�      ","iste   ","�      ","imos   ","eron   ","eron   ",
								   		  "ir�    ","ir�s   ","ir�    ","iremos ","ir�n   ","ir�n   ",
								   	 	  "�a     ","�as    ","�a     ","�amos  ","�an    ","�an    ",
								   		  "ir�a   ","ir�as  ","ir�a   ","ir�amos","ir�an  ","ir�an  "};		
enBasePronombres SubjuntivoSimpleBrunir={"a           ","as          ","a           ","amos        ","an          ","an          ",
									     "era         ","eras        ","era         ","�ramos      ","eran        ","eran        ",
									     "ere         ","eres        ","ere         ","�remos      ","eren        ","eren        "};	
//enBasePronombres SubjuntivoCompuestoBrunir Es igual al compuesto ER
enBasePronombres DesinenciaOtrosBrunir = {"endo ","ido","e t�"};

enBasePronombres DesinenciaSimpleReir  = {"�o      ","�es     ","�e      ","e�mos   ","�en     ","�en     ", //Presente
								   		  "e�      ","e�ste   ","io      ","e�mos   ","ieron   ","ieron   ", //Pret�rito perfecto simple 
								   		  "eir�    ","eir�s   ","eir�    ","eiremos ","eir�n   ","eir�n   ", //Futuro
								   	 	  "e�a     ","e�as    ","e�a     ","e�amos  ","e�an    ","e�an    ", //Pret�rito imperfecto
								   		  "eir�a   ","eir�as  ","eir�a   ","eir�amos","eir�an  ","eir�an  "}; //Condicional								   		  
enBasePronombres DesinenciaCompuestaReir={"e�do   ","e�do   ","e�do   ","e�do   ","e�do   ","e�do   ", //Pret�rito Perfecto Compuesto
									      "e�do   ","e�do   ","e�do   ","e�do   ","e�do   ","e�do   ", //Pret�rito anterior
									      "e�do   ","e�do   ","e�do   ","e�do   ","e�do   ","e�do   ",  //Futuro Compuesto
									      "e�do   ","e�do   ","e�do   ","e�do   ","e�do   ","e�do   ",  //Pret�rito pluscuamperfecto
									      "e�do   ","e�do   ","e�do   ","e�do   ","e�do   ","e�do   "}; //Condicional
enBasePronombres SubjuntivoSimpleReir={"�a          ","�as         ","�a          ","iamos       ","�an         ","�an         ", //presente
									   "iera        ","ieras       ","iera        ","i�ramos     ","ieran       ","ieran       ", //pret. imperfecto
									   "iere        ","ieres       ","iere        ","i�remos     ","ieren       ","ieren       "};//futuro
enBasePronombres DesinenciaOtrosReir = {"iendo ","eido","�e t�"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleAcertar={"ierto     ","iertas    ","ierta     ","ertamos   ","iertan    ","iertan    ", //Presente
								   		  "ert�      ","ertaste   ","ert�      ","ertamos   ","ertaron   ","ertaron   ", //Pret�rito perfecto simple 
								   		  "ertar�    ","ertar�s   ","ertar�    ","ertaremos ","ertar�n   ","ertar�n   ", //Futuro
								   	 	  "ertaba    ","ertabas   ","ertaba    ","ertabamos ","ertaban   ","ertaban   ", //Pret�rito imperfecto
								   		  "ertar�a   ","ertar�as  ","ertar�a   ","ertar�amos","ertar�an  ","ertar�an  "}; //Condicional								   		  
enBasePronombres DesinenciaCompuestaAcertar={"ertado ","ertado ","ertado ","ertado ","ertado ","ertado ", //Pret�rito Perfecto Compuesto
									         "ertado ","ertado ","ertado ","ertado ","ertado ","ertado ", //Pret�rito anterior
									         "ertado ","ertado ","ertado ","ertado ","ertado ","ertado ",  //Futuro Compuesto
									         "ertado ","ertado ","ertado ","ertado ","ertado ","ertado ",  //Pret�rito pluscuamperfecto
									         "ertado ","ertado ","ertado ","ertado ","ertado ","ertado "}; //Condicional
enBasePronombres SubjuntivoSimpleAcertar={"ierte       ","iertes      ","ierte       ","iertemos    ","ierten      ","ierten      ", //presente
									      "ertara      ","ertaras     ","ertaras     ","ert�ramos   ","ertaran     ","ertaran     ", //pret. imperfecto
									      "ertare      ","ertare      ","ertare      ","ert�remos   ","ertaren     ","ertaren     "};//futuro
enBasePronombres DesinenciaOtrosAcertar = {"ertando ","ertado","ierta t�"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

/*enBasePronombres DesinenciaSimpleErrar={};; //Condicional  	la misma que un regular con terminaci�n AR
enBasePronombres DesinenciaCompuestaErrar={}; //Condicional 
enBasePronombres SubjuntivoSimpleErrar={};//futuro
enBasePronombres DesinenciaOtrosErrar = {}; //Gerundio, Participio, Imperativo en la 2da persona del singular*/

enBasePronombres DesinenciaSimpleTender={"iendo     ","iendes    ","iende     ","endemos   ","ienden    ","ienden     ", //Presente
								   		 "e�        ","endiste   ","endi�     ","endimos   ","endieron  ","endieron   ", //Pret�rito perfecto simple 
								   	     "ender�    ","ender�s   ","ender�    ","enderemos ","ender�n   ","ender�n    ", //Futuro
								         "end�a     ","end�as    ","end�a     ","end�amos  ","end�an    ","end�an     ", //Pret�rito imperfecto
								   	     "ender�a   ","ender�as  ","ender�a   ","ender�amos","ender�an  ","ender�an   "}; //Condicional								   		  
enBasePronombres DesinenciaCompuestaTender={"endido ","endido ","endido ","endido ","endido ","endido ", //Pret�rito Perfecto Compuesto
									        "endido ","endido ","endido ","endido ","endido ","endido ", //Pret�rito anterior
									        "endido ","endido ","endido ","endido ","endido ","endido ",  //Futuro Compuesto
									        "endido ","endido ","endido ","endido ","endido ","endido ",  //Pret�rito pluscuamperfecto
									        "endido ","endido ","endido ","endido ","endido ","endido "}; //Condicional
enBasePronombres SubjuntivoSimpleTender={"ienda     ","iendas    ","ienda     ","endamos   ","iendan    ","iendan    ", //presente
									     "endiere   ","endieras  ","endiera   ","endi�ramos","endieran  ","endieran  ", //pret. imperfecto
									     "endiere   ","endieres  ","endiere   ","endi�remos","endieren  ","endieren  "};//futuro
enBasePronombres DesinenciaOtrosTender= {"endiendo ","endido","iende t�"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleQuerer={"iero     ","ieres    ","iere     ","eremos   ","ieren    ","ieren    ", //Presente
								   		 "er�      ","eriste   ","eri�     ","erimos   ","erieron  ","erieron  ", //Pret�rito perfecto simple 
								   	     "err�     ","err�s    ","err�     ","erremos  ","err�n    ","err�n    ", //Futuro
								         "er�a     ","er�as    ","er�a     ","er�amos  ","er�an    ","er�an    ", //Pret�rito imperfecto
								   	     "err�a    ","err�as   ","err�a    ","err�amos ","err�an   ","err�an   "}; //Condicional								   		  
enBasePronombres DesinenciaCompuestaQuerer={"erido  ","erido  ","erido  ","erido  ","erido  ","erido  ", //Pret�rito Perfecto Compuesto
									        "erido  ","erido  ","erido  ","erido  ","erido  ","erido  ", //Pret�rito anterior
									        "erido  ","erido  ","erido  ","erido  ","erido  ","erido  ",  //Futuro Compuesto
									        "erido  ","erido  ","erido  ","erido  ","erido  ","erido  ",  //Pret�rito pluscuamperfecto
									        "erido  ","erido  ","erido  ","erido  ","erido  ","erido  "}; //Condicional
enBasePronombres SubjuntivoSimpleQuerer={"iera     ","ieras    ","iera     ","eramos   ","ieran    ","ieran    ", //presente
									     "isiera   ","isieras  ","isiera   ","isi�ramos","isieran  ","isieran  ", //pret. imperfecto
									     "isiere   ","isieres  ","isiere   ","isi�remos","isieren  ","isieren  "};//futuro
enBasePronombres DesinenciaOtrosQuerer= {"eriendo ","erido","iere t�"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleTener={"engo     ","ienes    ","iene     ","enemos   ","ienen    ","ienen    ", //Presente
								   		"uve      ","uviste   ","uvo      ","uvimos   ","uvieron  ","uvieron  ", //Pret�rito perfecto simple 
								   	    "endr�    ","endr�s   ","endr�    ","endremos ","endr�n   ","endr�n   ", //Futuro
								        "en�a     ","en�as    ","en�a     ","en�amos  ","en�an    ","en�an    ", //Pret�rito imperfecto
								   	    "endr�a   ","endr�as  ","endr�a   ","endr�amos","endr�an  ","endr�an  "}; //Condicional
								   		  
enBasePronombres DesinenciaCompuestaTener={"enido  ","enido  ","enido  ","enido  ","enido  ","enido  ", //Pret�rito Perfecto Compuesto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ", //Pret�rito anterior
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ",  //Futuro Compuesto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ",  //Pret�rito pluscuamperfecto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  "}; //Condicional
enBasePronombres SubjuntivoSimpleTener={"enga      ","engas    ","enga     ","engamos  ","engan    ","engan    ", //presente
									    "uviera    ","uvieras  ","uviera   ","uvi�ramos","uvieran  ","uvieran  ", //pret. imperfecto
									    "uviere    ","uvieres  ","uviere   ","uvi�remos","uvieren  ","uvieren  "};//futuro
enBasePronombres DesinenciaOtrosTener= {"eniendo ","enido","en t�"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimplePoner={"ongo     ","ones     ","one      ","onemos   ","onen     ","onen     ", //Presente
								   		"use      ","usiste   ","uso      ","usimos   ","usieron  ","usieron  ", //Pret�rito perfecto simple 
								   	    "ondr�    ","ondr�s   ","ondr�    ","ondremos ","ondr�n   ","ondr�n   ", //Futuro
								        "on�a     ","on�as    ","on�a     ","on�amos  ","on�an    ","on�an    ", //Pret�rito imperfecto
								   	    "ondr�a   ","ondr�as  ","ondr�a   ","ondr�amos","ondr�an  ","ondr�an  "}; //Condicional
enBasePronombres DesinenciaCompuestaPoner={ "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  ", //Pret�rito Perfecto Compuesto
									        "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  ", //Pret�rito anterior
									        "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  ",  //Futuro Compuesto
									        "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  ",  //Pret�rito pluscuamperfecto
									        "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  "}; //Condicional
enBasePronombres SubjuntivoSimplePoner={"onga      ","ongas    ","onga     ","ongamos  ","ongan    ","ongan    ", //presente
									    "usiera    ","usieras  ","usiera   ","usi�ramos","usieran  ","usieran  ", //pret. imperfecto
									    "usiere    ","usieres  ","usiere   ","usi�remos","usieren  ","usieren  "};//futuro
enBasePronombres DesinenciaOtrosPoner= {"oniendo ","uesto","on t�"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleDiscernir={"ierno     ","iernes    ","ierne     ","ernimos   ","iernen    ","iernen    ", //Presente
								   		    "ern�      ","erniste   ","erni�     ","ernimos   ","ernieron  ","ernieron  ", //Pret�rito perfecto simple 
								   	        "ernir�    ","ernir�s   ","ernir�    ","erniremos ","ernir�n   ","ernir�n   ", //Futuro
								    	    "ern�a     ","ern�as    ","ern�a     ","ern�amos  ","ern�an    ","ern�an    ", //Pret�rito imperfecto
								   	        "ernir�a   ","ernir�as  ","ernir�a   ","ernir�amos","ernir�an  ","ernir�an  "}; //Condicional
enBasePronombres DesinenciaCompuestaDiscernir={ "ernido ","ernido ","ernido ","ernido ","ernido ","ernido ", //Pret�rito Perfecto Compuesto
									        	"ernido ","ernido ","ernido ","ernido ","ernido ","ernido ", //Pret�rito anterior
									        	"ernido ","ernido ","ernido ","ernido ","ernido ","ernido ",  //Futuro Compuesto
									        	"ernido ","ernido ","ernido ","ernido ","ernido ","ernido ",  //Pret�rito pluscuamperfecto
									        	"ernido ","ernido ","ernido ","ernido ","ernido ","ernido "}; //Condicional
enBasePronombres SubjuntivoSimpleDiscernir={"ierna     ","iernas   ","ierna    ","iernamos  ","iernan   ","iernan   ", //presente
									    	"erniera   ","ernieras ","erniera  ","erni�ramos","ernieran ","ernieran ", //pret. imperfecto
									    	"erniere   ","ernieres ","erniere  ","erni�remos","ernieren ","ernieren "};//futuro
enBasePronombres DesinenciaOtrosDiscernir= {"erniendo ","ernido","ierne t�"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleVenir={"engo     ","ienes    ","iene     ","enimos   ","ienen    ","ienen    ", //Presente
								   		"ine      ","iniste   ","ino      ","inimos   ","inieron  ","inieron  ", //Pret�rito perfecto simple 
								   	    "endr�    ","end�s    ","endr�    ","endremos ","endr�n   ","endr�n   ", //Futuro
								    	"en�a     ","en�as    ","en�a     ","en�amos  ","en�an    ","en�an    ", //Pret�rito imperfecto
								   	    "endr�a   ","endr�as ","endr�a  ","endr�amos","endr�an ","endr�an "}; //Condicional
enBasePronombres DesinenciaCompuestaVenir={ "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ", //Pret�rito Perfecto Compuesto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ", //Pret�rito anterior
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ",  //Futuro Compuesto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ",  //Pret�rito pluscuamperfecto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  "}; //Condicional
enBasePronombres SubjuntivoSimpleVenir={"enga      ","engas    ","enga     ","engamos   ","engan    ","engan    ", //presente
									    "iniera    ","inieras  ","iniera   ","ini�ramos ","inieran  ","inieran  ", //pret. imperfecto
									    "iniere    ","inieres  ","iniere   ","ini�remos ","inieren  ","inieren  "};//futuro
enBasePronombres DesinenciaOtrosVenir= {"erniendo ","ernido","ierne t�"}; //Gerundio, Participio, Imperativo en la 2da persona del singular


enBasePronombres Pronombres = {"yo", "t�", "�l", "nosotros","ustedes" ,"ellos"};                                                                             
enBasePronombres comp = {"he   ","has  ","ha   ","hemos","han  ","han  ",
						 "hube    ","hubiste ","hubo    ","hubimos ","hubieron","hubieron",
						 "habr�   ","habr�s  ","habr�   ","habremos","habr�n  ","habr�n  ",
						 "hab�a   ","hab�as  ","hab�a   ","hab�amos","hab�an  ","hab�an  ",
						 "habr�a   ","habr�as  ","habr�a   ","habr�amos","habr�an  ","habr�an  "};
enBasePronombres Scomp = {"haya   ","hayas  ","haya   ","hayamos","hayan  ","hayan  ",
						  "hubiera   ","hubieras  ","hubiera   ","hubi�ramos","hubieran  ","hubieran  ",
						  "hubiere   ","hubieres  ","hubiere   ","hubi�remos","hubieren  ","hubieren  "};

/*Para comparar los caracteres � y � fueron remplazados por su equivalente hexadecimal*/
char *verbos[]={"bru\xa4ir","engullir","u\xa4ir","mu\xa4ir","bullir","gua\xa4ir","reti\xa4ir","constri\xa4ir","gru\xa4ir","remullir","zu\xa4ir","rebullir","tollir", //12 o 13
      "desga\xa4ir","hi\xa4ir","escullir","zambullir","fallir","alba\xa4ir","junir","lullir", // 19 o 20
		  "re\xa1r","fre\xa1r", // 21 o 22
		  "acertar","concertar","dispertar","despertar","desacertar","desconcertar", //27 o 28
		  "errar", //28 o 29
		  "tender","ascender","entender","encender","subentender","deshender","destender","hender","atender","extender","trascender",
	      "sobretender","malentender","reencender","distender","descender","defender","transcender","desatender","contender",
		  "querer","desquerer","bienquerer","malquerer",
		  "tener",
		  "poner",
		  "discernir","cernir","decernir",
		  "venir"};
char *verbosE[]={"bru�ir","engullir","u�ir","mu�ir","bullir","gua�ir","reti�ir","constri�ir","gru�ir","remullir","zu�ir","rebullir","tollir", //12 o 13
      "desga�ir","hi�ir","escullir","zambullir","fallir","alba�ir","junir","lullir", // 19 
		  "re�r","fre�r", // 21 
		  "acertar","concertar","dispertar","despertar","desacertar","desconcertar", //27 
		  "errar", //28 
		  "tender","ascender","entender","encender","subentender","deshender","destender","hender","atender","extender","trascender",
	  "sobretender","malentender","reencender","distender","descender","defender","transcender","desatender","contender", //48
		  "querer","desquerer","bienquerer","malquerer", //52
		  "tener", //53
		  "poner", //54
		  "discernir","cernir","decernir", //57
		  "venir"}; //58
 char *definiciones[]={"Sacar brillo o lustre a una cosa, en especial a un metal.",//0
 		"Tragar algo precipitadamente, de golpe o sin moderaci�n.",
 		"Juntar dos o m�s elementos distintos para formar un todo.",
 		"Concertar, disponer o manejar un asunto, especialmente si se hace en inter�s o provecho propios.",
 		"Producir [un l�quido] burbujas que suben desde el interior del mismo y estallan al llegar a la superficie, cuando este alcanza una temperatura determinada, por fermentaci�n o por efervescencia.",
 		"Cerrar y abrir un ojo r�pidamente dejando el otro abierto.",
 		"Sonido repetido en los o�dos de una campana u otra cosa.",
 		"Forzar a alguien a hacer algo que no quiere.",
 		"Emitir [una persona] sonidos no articulados o palabras murmuradas entre dientes que muestran su enfado o desagrado.",//8
		"Agitarse una cosa dentro de algo.",
		"Reforzar con abrazaderas met�licas.",//10
		"Agitarse una cosa dentro de algo.",
		"Hacer que una persona quede imposibilitada de moverse.",
		"Elegir a alguien o algo para cumplir una tarea.",
		"Insertar una cosa en otra.",
		"Labrar a mano una obra en alg�n material.",
		"Meter con �mpetu algo o a alguien dentro del agua u otro l�quido.",
		"Tener algo un error o una equivocaci�n.",
		"Persona que construye edificios u otras obras.",
		"Atar o sujetar al yugo bueyes, mulas u otras bestias.",
		"Frotar, estregar, rozar algo con otra cosa.",//20
		"Manifestar alegr�a, placer o felicidad mediante ciertos movimientos de la boca, los ojos y otras partes de la cara, acompa�ados de la emisi�n de una serie de sonidos explosivos e inarticulados.",
		"Cocinar un alimento en aceite u otro tipo de grasa hirviendo.",
		"Dar un golpe, un disparo, etc., en el lugar previsto o propuesto o en el punto preciso al que se dirigi�.",
		"Hacer que alguien deje de dormir o interrumpir el sue�o de alguien.",
		"Razonar con detenimiento sobre un tema, especialmente en p�blico",
		"Hacer que una persona no sepa c�mo reaccionar ni qu� pensar o decir, generalmente por medio de algo inesperado o sorprendente.",
		"No tener acierto al hacer una cosa o al obrar o actuar de una determinada manera.",
		"Hacer que dos o m�s cosas armonicen o act�en de forma conjunta.",
		"Cometer un error o equivocarse en cierta cosa.",
		"Extender o estirar una cosa horizontalmente.",
		"Ir de un lugar alto a otro m�s bajo.",
		"Sobrepasar [una cosa] un determinado l�mite.",
		"Hacer que una cosa ocupe m�s espacio del que ocupa, abri�ndola, desdobl�ndola, desenroll�ndola, etc.",
		"Percibir o notar la idea de un modo preciso y claro en lo que se dice, hace o sucede",
		"Fingir que no se entiende cierta cosa o afectar ignorancia.",
		"Entender algo que no est� expreso pero que se supone o se deduce.",
		"Hacer una hendedura",
		"Guardar o proteger contra un ataque, un peligro o un da�o.",
		"Percibir y tener una idea clara de lo que se dice, se hace o sucede o descubrir el sentido profundo de algo.",
		"Hacer que prenda una cosa que est� especialmente preparada o adaptada para ello, aplic�ndole fuego o haciendo que el fuego brote de ella.",
		"Entender o interpretar mal una cosa.",
		"Asumir o entender algo que, aunque no est� expresado expl�citamente, se puede suponer de manera l�gica por el contexto.",
		"Entender algo que no est� expreso pero que se supone o se deduce.",
		"Luchar entre s� [varias personas, animales o cosas que aspiran a un mismo objetivo o a la superioridad en algo]."
		"Ir de un lugar a otro m�s alto.",
		"Aplicar voluntariamente la actividad mental o los sentidos a un determinado est�mulo u objeto mental o sensible.",
		"Hacer menos tensa o tirante una relaci�n, una situaci�n u otra circunstancia.",
		"Acomodarse o adaptarse [una persona] al gusto y la voluntad de otra.",
		"Inspeccionar, vigilar, gobernar.",
		"Extenderse a la vez que otro.",
		"Tener el deseo, la voluntad o la intenci�n de hacer, poseer o lograr algo.",
		"Tener animadversi�n hacia una persona.",
		"Querer el bien para los dem�s.",
		"Dejar de querer.",
		"Indica que lo expresado por el complemento directo tiene una relaci�n, especialmente de posesi�n, pertenencia o inclusi�n, con la persona o cosa designada por el sujeto.",
		"Hacer que una persona o una cosa est� en un lugar determinado.",
		"Distinguir por medio del intelecto una cosa de otra o varias cosas entre ellas.",
		"Separar con el cedazo o la criba la parte fina de una materia reducida a polvo de las partes m�s gruesas.",
		"Decidir la diferencia entre cosas; otorgar un cargo o distinci�n",
		"Ir hacia el lugar donde est� la persona que habla."};
 		
int conjugacionRegular(FILE *archivo, char raizVerboAR[],enBasePronombres DesinenciaSimple,enBasePronombres DesinenciaCompuesta,
						enBasePronombres SubjuntivoS,enBasePronombres DesinenciaOtros,int quitar);
int aux(char **Modo,FILE *archivo,char raizVerboAR[],enBasePronombres Desinencia,int TotalTiempos,enBasePronombres hub,int lpronombre, int reg);

int main(int argc, char *argv[]){                               
  FILE *miArchivo;              
  char buffer[128],a;             
  int lbuffer,i,j,k,ldef;                  

  miArchivo = fopen("misVerbos.txt", "a");

  if (miArchivo == NULL){
    fprintf(stderr, "No se pudo abrir el archivo \"misVerbos.txt\"\n");
    return 0;                                                          
  }                                                                    
  printf("Escriba un verbo regular o uno listado "
  		 "\n(ADVERTENCIA: No atender a esta instrucci�n ocasionar� un resultado inesperado ) \n");  
  
  /*Imprime la lista de verbos*/
  for(k=1; k<=58;k++){
  	 printf("%12s ",verbos[k-1]);
  	 if(k%6 == 0)
  	 	printf("\n");
  }
  printf("\n Verbo: ");
  scanf("%s", buffer);
  
  printf("Por conjugar verbo\n"); 
  lbuffer = strlen(buffer);

  int num =-1; /* Si es 1 es irregular, si es -1 es regular*/
  for(i=0; i<= 58 ;i++)
  	if(strncmp(verbos[i],buffer,lbuffer) == 0){ /*Compara el verbo ingresado con los de la lista en hexadecimal */
  		  //printf("%d",i);
  		  for(j=0;j<lbuffer;j++)
  		  	buffer[j] = verbosE[i][j];  /*Escribe los verbos de la lista sin hexadecimal*/
  		  num = 1;
		  break;}
  
  /*Escribe las definiciones*/
  /*ldef = strlen(definiciones[i]);
  for(k=0; k <= ldef;k++)*/
  if(num == 1)
  		fprintf(miArchivo,"%s. \nDefinici�n: %s \n",verbosE[i],definiciones[i]);
  
  if(num==1){
  	/*Conjugar como verbo irregular*/
  	if( 0<=i && i<=19){
  		/*conjugar modelo bru�ir*/
  		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleBrunir,DesinenciaCompuestaER,
		  				   SubjuntivoSimpleBrunir,DesinenciaOtrosBrunir,2);	
	}
	if( i==20 || i==21){
  		/*conjugar modelo reir*/
		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleReir,DesinenciaCompuestaReir,
		  				   SubjuntivoSimpleReir,DesinenciaOtrosReir,3);
	}
	if( 22<=i && i<=27){
  		/*conjugar modelo acertar*/
  		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleAcertar,DesinenciaCompuestaAcertar,
		  				   SubjuntivoSimpleAcertar,DesinenciaOtrosAcertar,5);
	}
	if( i == 28){
		/*conjugar modelo errar*/
  		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleAR,DesinenciaCompuestaAR,
			  				SubjuntivoSimpleAR,DesinenciaOtrosAR,2);
	}
 	if( 29<=i && i<=48){
  		/*conjugar modelo tender*/
  		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleTender,DesinenciaCompuestaTender,
			  				SubjuntivoSimpleTender,DesinenciaOtrosTender,5);
	}
	if( 49<=i && i<=52){
  		/*conjugar modelo querer*/
  		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleQuerer,DesinenciaCompuestaQuerer,
			  				SubjuntivoSimpleQuerer,DesinenciaOtrosQuerer,4);
  	}
	if( i == 53 ){
  		/*conjugar modelo tener*/
  		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleTener,DesinenciaCompuestaTener,
			  				SubjuntivoSimpleTener,DesinenciaOtrosTener,4);
	}
	if(i==54){
  		/*conjugar modelo poner*/
  		conjugacionRegular(miArchivo, buffer,DesinenciaSimplePoner,DesinenciaCompuestaPoner,
			  				SubjuntivoSimplePoner,DesinenciaOtrosPoner,4);
	}
	if( 55<=i && i<=57){
  		/*conjugar modelo discernir*/
  		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleDiscernir,DesinenciaCompuestaDiscernir,
			  				SubjuntivoSimpleDiscernir,DesinenciaOtrosDiscernir,5);
	}
	if( i==58){
  		/*conjugar modelo venir*/
  		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleVenir,DesinenciaCompuestaVenir,
			  				SubjuntivoSimpleVenir,DesinenciaOtrosVenir,4);
	}
  }

  if(num == -1){
  	  a = buffer[lbuffer-2];   
	  switch(a){
	  	case 'a':
		  	conjugacionRegular(miArchivo, buffer,DesinenciaSimpleAR,DesinenciaCompuestaAR,
			  				   SubjuntivoSimpleAR,DesinenciaOtrosAR,2 /*Letras que se le quitan al buffer*/);
			break; 
	  	case 'e':
	  	    conjugacionRegular(miArchivo, buffer,DesinenciaSimpleER,DesinenciaCompuestaER,
			  				   SubjuntivoSimpleER,DesinenciaOtrosER,2);
		    break;
	  	case 'i':
	  		conjugacionRegular(miArchivo, buffer,DesinenciaSimpleIR,DesinenciaCompuestaER,
			   				   SubjuntivoSimpleIR,DesinenciaOtrosIR,2);
		    break;
	  }
  }

  printf("Verbo Conjugado\n");                    
  fclose(miArchivo);
  printf("FIN\n");

  return 0;
}          

int conjugacionRegular(FILE *archivo, char raizVerboAR[],enBasePronombres DesinenciaSimple,enBasePronombres DesinenciaCompuesta,
						enBasePronombres SubjuntivoS,enBasePronombres DesinenciaOtros, int quitar)                                                                          
{                                                                                
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];
  int lbuffer = strlen(raizVerboAR);                                                          
  lverbo = strlen(raizVerboAR)+2;  
  raizVerboAR[lbuffer-quitar]= '\0';
  /*Indicativo Simple*/
  aux(ModoIndicativoSimple,archivo,raizVerboAR,DesinenciaSimple,TotalTiemposSimples,comp,7,1/*1 para simple, 2 para compuesto*/);
  fprintf(archivo,"\n\n");
  /*Indicativo Compuesto*/
  aux(ModoIndicativoCompuesto,archivo,raizVerboAR,DesinenciaCompuesta,TotalTiemposSimples,comp,15,2);
  fprintf(archivo,"\n\n");
  /*Subjuntivo Simple*/
  aux(ModoSubjuntivoSimple,archivo,raizVerboAR,SubjuntivoS,TotalTiemposSubjuntivosS,comp,7,1);
  fprintf(archivo,"\n\n");
  /*Subjuntivo Compuesto*/
  aux(ModoSubjuntivoCompuesto,archivo,raizVerboAR,DesinenciaCompuesta,TotalTiemposSubjuntivosC,Scomp,10,2);
  fprintf(archivo,"\n\n");
  /* Participio, Gerundio, Imperativo en la segunda persona del singular*/
  fprintf(archivo,"Gerundio    Participio   Imperativo de la segunda persona del singular \n");
  fprintf(archivo,"%s%s     %s%s     %s%s   ",raizVerboAR,DesinenciaOtros[0],raizVerboAR,DesinenciaOtros[1],raizVerboAR,DesinenciaOtros[2]);
  fprintf(archivo,"\n\n");
  return 0;  
}            

int aux(char **Modo,FILE *archivo,char raizVerboAR[],enBasePronombres Desinencia,int TotalTiempos,enBasePronombres hub,int lpronombre, int reg)
{
	int ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
    char formato[1024];
    lverbo = strlen(raizVerboAR)+2;
	for(tiempo=0;tiempo<TotalTiempos;tiempo++){  //  <TotalTiempos  era <=4
		titulo = strlen(Modo[tiempo])/2;
		centrado = (lverbo+lpronombre+ldesidencia+1)/2;  
		if (centrado<=titulo) centrado=0;
			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
		fprintf(archivo, formato, " ", Modo[tiempo]," ");
	}
   fprintf(archivo,"\n\n");
	for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<TotalTiempos*TotalPronombres;tiempo+=6){
			if(reg == 1)
				fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboAR, Desinencia[tiempo]);
			else  //if(reg == 2)
			    fprintf(archivo, "%8s %s %s%s", Pronombres[persona],hub[tiempo],raizVerboAR, Desinencia[tiempo]);
	}		
	fprintf(archivo, "\n");
	}                                     
	fprintf(archivo, "\n");
	return 0;
}
