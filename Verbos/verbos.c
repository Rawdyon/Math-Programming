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

char *ModoIndicativoSimple[]={"Presente", "Pretérito", "Futuro",
                             "Copretérito", "Postpretérito"};
                             //Presente, Pretérito perfecto simple , Futuro, Pretérito imperfecto, Condicional
char *ModoIndicativoCompuesto[]={"Antepresente", "Antepretérito", "Antefuturo",
                             "Antecopretérito", "Antepostpretérito"};
 /*char *ModoIndicativoCompuesto[]={"Pretérito Perfecto Compuesto", "Pretérito anterior", "Futuro Compuesto", "Pretérito pluscuamperfecto", "Condicional"};*/  
char *ModoSubjuntivoSimple[]={"Subjuntivo Presente","Subjuntivo Pretérito","Subjuntivo Futuro"};
char *ModoSubjuntivoCompuesto[]={"Subjuntivo Antepresente", "Subjuntivo Antepretérito", "Subjuntivo Antefuturo"};
char *ModoOtros[]={"Gerundio" ,"Participio","Imperativo en la segunda persona del singular"};
                                                                        
enBasePronombres DesinenciaSimpleAR = {"o      ","as     ","a      ","amos   ","an     ","an     ",
									   "é      ","aste   ","o      ","amos   ","aron   ","aron   ",
									   "aré    ","arás   ","ará    ","aremos ","arán   ","arán   ",
									   "aba    ","abas   ","aba    ","ábamos ","aban   ","aban   ",
									   "aría   ","arías  ","aría   ","aríamos","arían  ","arían  "};
enBasePronombres DesinenciaSimpleER = {"o      ","es     ","e      ","emos   ","en     ","en     ",
									   "í      ","iste   ","ió     ","imos   ","ieron  ","ieron  ",
									   "eré    ","erás   ","erá    ","eremos ","erán   ","erán   ",
									   "ía     ","ías    ","ía     ","íamos  ","ían    ","ían    ",
									   "ería   ","erías  ","ería   ","eríamos","erían  ","erían  "};									   
enBasePronombres DesinenciaSimpleIR = {"o      ","es     ","e      ","imos   ","en     ","en     ",
									   "í      ","iste   ","ió     ","imos   ","ieron  ","ieron  ",
									   "iré    ","irás   ","irá    ","iremos ","irán   ","irán   ",
									   "ía     ","ías    ","ía     ","íamos  ","ían    ","ían    ",
									   "iría   ","irías  ","iría   ","iríamos","irían  ","irían  "}; 

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
									   "ara         ","aras        ","ara         ","áramos      ","aran        ","aran        ",
									   "are         ","ares        ","are         ","áremos      ","aren        ","aren        "};						   	  
enBasePronombres SubjuntivoSimpleER = {"a           ","as          ","a           ","amos        ","an          ","an          ",
									   "iera        ","ieras       ","iera        ","iéramos     ","ieran       ","ieran       ",
									   "iere        ","ieres       ","iere        ","iéremos     ","ieren       ","ieren       "};
enBasePronombres SubjuntivoSimpleIR = {"a           ","as          ","a           ","amos        ","an          ","an          ",
									   "iera        ","ieras       ","iera        ","iéramos     ","ieran       ","ieran       ",
									   "iere        ","ieres       ","iere        ","iéremos     ","ieren       ","ieren       "};									  
										  					   
enBasePronombres DesinenciaOtrosAR = {"ando ","ado","a tú"};
enBasePronombres DesinenciaOtrosER = {"iendo","ido","e tú"};
enBasePronombres DesinenciaOtrosIR = {"iendo","ido","e tú"};

enBasePronombres DesinenciaSimpleBrunir= {"o      ","es     ","e      ","imos   ","en     ","en     ",
								   		  "í      ","iste   ","ó      ","imos   ","eron   ","eron   ",
								   		  "iré    ","irás   ","irá    ","iremos ","irán   ","irán   ",
								   	 	  "ía     ","ías    ","ía     ","íamos  ","ían    ","ían    ",
								   		  "iría   ","irías  ","iría   ","iríamos","irían  ","irían  "};		
enBasePronombres SubjuntivoSimpleBrunir={"a           ","as          ","a           ","amos        ","an          ","an          ",
									     "era         ","eras        ","era         ","éramos      ","eran        ","eran        ",
									     "ere         ","eres        ","ere         ","éremos      ","eren        ","eren        "};	
//enBasePronombres SubjuntivoCompuestoBrunir Es igual al compuesto ER
enBasePronombres DesinenciaOtrosBrunir = {"endo ","ido","e tú"};

enBasePronombres DesinenciaSimpleReir  = {"ío      ","íes     ","íe      ","eímos   ","íen     ","íen     ", //Presente
								   		  "eí      ","eíste   ","io      ","eímos   ","ieron   ","ieron   ", //Pretérito perfecto simple 
								   		  "eiré    ","eirás   ","eirá    ","eiremos ","eirán   ","eirán   ", //Futuro
								   	 	  "eía     ","eías    ","eía     ","eíamos  ","eían    ","eían    ", //Pretérito imperfecto
								   		  "eiría   ","eirías  ","eiría   ","eiríamos","eirían  ","eirían  "}; //Condicional								   		  
enBasePronombres DesinenciaCompuestaReir={"eído   ","eído   ","eído   ","eído   ","eído   ","eído   ", //Pretérito Perfecto Compuesto
									      "eído   ","eído   ","eído   ","eído   ","eído   ","eído   ", //Pretérito anterior
									      "eído   ","eído   ","eído   ","eído   ","eído   ","eído   ",  //Futuro Compuesto
									      "eído   ","eído   ","eído   ","eído   ","eído   ","eído   ",  //Pretérito pluscuamperfecto
									      "eído   ","eído   ","eído   ","eído   ","eído   ","eído   "}; //Condicional
enBasePronombres SubjuntivoSimpleReir={"ía          ","ías         ","ía          ","iamos       ","ían         ","ían         ", //presente
									   "iera        ","ieras       ","iera        ","iéramos     ","ieran       ","ieran       ", //pret. imperfecto
									   "iere        ","ieres       ","iere        ","iéremos     ","ieren       ","ieren       "};//futuro
enBasePronombres DesinenciaOtrosReir = {"iendo ","eido","íe tú"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleAcertar={"ierto     ","iertas    ","ierta     ","ertamos   ","iertan    ","iertan    ", //Presente
								   		  "erté      ","ertaste   ","ertó      ","ertamos   ","ertaron   ","ertaron   ", //Pretérito perfecto simple 
								   		  "ertaré    ","ertarás   ","ertará    ","ertaremos ","ertarán   ","ertarán   ", //Futuro
								   	 	  "ertaba    ","ertabas   ","ertaba    ","ertabamos ","ertaban   ","ertaban   ", //Pretérito imperfecto
								   		  "ertaría   ","ertarías  ","ertaría   ","ertaríamos","ertarían  ","ertarían  "}; //Condicional								   		  
enBasePronombres DesinenciaCompuestaAcertar={"ertado ","ertado ","ertado ","ertado ","ertado ","ertado ", //Pretérito Perfecto Compuesto
									         "ertado ","ertado ","ertado ","ertado ","ertado ","ertado ", //Pretérito anterior
									         "ertado ","ertado ","ertado ","ertado ","ertado ","ertado ",  //Futuro Compuesto
									         "ertado ","ertado ","ertado ","ertado ","ertado ","ertado ",  //Pretérito pluscuamperfecto
									         "ertado ","ertado ","ertado ","ertado ","ertado ","ertado "}; //Condicional
enBasePronombres SubjuntivoSimpleAcertar={"ierte       ","iertes      ","ierte       ","iertemos    ","ierten      ","ierten      ", //presente
									      "ertara      ","ertaras     ","ertaras     ","ertáramos   ","ertaran     ","ertaran     ", //pret. imperfecto
									      "ertare      ","ertare      ","ertare      ","ertáremos   ","ertaren     ","ertaren     "};//futuro
enBasePronombres DesinenciaOtrosAcertar = {"ertando ","ertado","ierta tú"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

/*enBasePronombres DesinenciaSimpleErrar={};; //Condicional  	la misma que un regular con terminación AR
enBasePronombres DesinenciaCompuestaErrar={}; //Condicional 
enBasePronombres SubjuntivoSimpleErrar={};//futuro
enBasePronombres DesinenciaOtrosErrar = {}; //Gerundio, Participio, Imperativo en la 2da persona del singular*/

enBasePronombres DesinenciaSimpleTender={"iendo     ","iendes    ","iende     ","endemos   ","ienden    ","ienden     ", //Presente
								   		 "eí        ","endiste   ","endió     ","endimos   ","endieron  ","endieron   ", //Pretérito perfecto simple 
								   	     "enderé    ","enderás   ","enderá    ","enderemos ","enderán   ","enderán    ", //Futuro
								         "endía     ","endías    ","endía     ","endíamos  ","endían    ","endían     ", //Pretérito imperfecto
								   	     "endería   ","enderías  ","endería   ","enderíamos","enderían  ","enderían   "}; //Condicional								   		  
enBasePronombres DesinenciaCompuestaTender={"endido ","endido ","endido ","endido ","endido ","endido ", //Pretérito Perfecto Compuesto
									        "endido ","endido ","endido ","endido ","endido ","endido ", //Pretérito anterior
									        "endido ","endido ","endido ","endido ","endido ","endido ",  //Futuro Compuesto
									        "endido ","endido ","endido ","endido ","endido ","endido ",  //Pretérito pluscuamperfecto
									        "endido ","endido ","endido ","endido ","endido ","endido "}; //Condicional
enBasePronombres SubjuntivoSimpleTender={"ienda     ","iendas    ","ienda     ","endamos   ","iendan    ","iendan    ", //presente
									     "endiere   ","endieras  ","endiera   ","endiéramos","endieran  ","endieran  ", //pret. imperfecto
									     "endiere   ","endieres  ","endiere   ","endiéremos","endieren  ","endieren  "};//futuro
enBasePronombres DesinenciaOtrosTender= {"endiendo ","endido","iende tú"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleQuerer={"iero     ","ieres    ","iere     ","eremos   ","ieren    ","ieren    ", //Presente
								   		 "erí      ","eriste   ","erió     ","erimos   ","erieron  ","erieron  ", //Pretérito perfecto simple 
								   	     "erré     ","errás    ","errá     ","erremos  ","errán    ","errán    ", //Futuro
								         "ería     ","erías    ","ería     ","eríamos  ","erían    ","erían    ", //Pretérito imperfecto
								   	     "erría    ","errías   ","erría    ","erríamos ","errían   ","errían   "}; //Condicional								   		  
enBasePronombres DesinenciaCompuestaQuerer={"erido  ","erido  ","erido  ","erido  ","erido  ","erido  ", //Pretérito Perfecto Compuesto
									        "erido  ","erido  ","erido  ","erido  ","erido  ","erido  ", //Pretérito anterior
									        "erido  ","erido  ","erido  ","erido  ","erido  ","erido  ",  //Futuro Compuesto
									        "erido  ","erido  ","erido  ","erido  ","erido  ","erido  ",  //Pretérito pluscuamperfecto
									        "erido  ","erido  ","erido  ","erido  ","erido  ","erido  "}; //Condicional
enBasePronombres SubjuntivoSimpleQuerer={"iera     ","ieras    ","iera     ","eramos   ","ieran    ","ieran    ", //presente
									     "isiera   ","isieras  ","isiera   ","isiéramos","isieran  ","isieran  ", //pret. imperfecto
									     "isiere   ","isieres  ","isiere   ","isiéremos","isieren  ","isieren  "};//futuro
enBasePronombres DesinenciaOtrosQuerer= {"eriendo ","erido","iere tú"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleTener={"engo     ","ienes    ","iene     ","enemos   ","ienen    ","ienen    ", //Presente
								   		"uve      ","uviste   ","uvo      ","uvimos   ","uvieron  ","uvieron  ", //Pretérito perfecto simple 
								   	    "endré    ","endrás   ","endrá    ","endremos ","endrán   ","endrán   ", //Futuro
								        "enía     ","enías    ","enía     ","eníamos  ","enían    ","enían    ", //Pretérito imperfecto
								   	    "endría   ","endrías  ","endría   ","endríamos","endrían  ","endrían  "}; //Condicional
								   		  
enBasePronombres DesinenciaCompuestaTener={"enido  ","enido  ","enido  ","enido  ","enido  ","enido  ", //Pretérito Perfecto Compuesto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ", //Pretérito anterior
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ",  //Futuro Compuesto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ",  //Pretérito pluscuamperfecto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  "}; //Condicional
enBasePronombres SubjuntivoSimpleTener={"enga      ","engas    ","enga     ","engamos  ","engan    ","engan    ", //presente
									    "uviera    ","uvieras  ","uviera   ","uviéramos","uvieran  ","uvieran  ", //pret. imperfecto
									    "uviere    ","uvieres  ","uviere   ","uviéremos","uvieren  ","uvieren  "};//futuro
enBasePronombres DesinenciaOtrosTener= {"eniendo ","enido","en tú"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimplePoner={"ongo     ","ones     ","one      ","onemos   ","onen     ","onen     ", //Presente
								   		"use      ","usiste   ","uso      ","usimos   ","usieron  ","usieron  ", //Pretérito perfecto simple 
								   	    "ondré    ","ondrás   ","ondrá    ","ondremos ","ondrán   ","ondrán   ", //Futuro
								        "onía     ","onías    ","onía     ","oníamos  ","onían    ","onían    ", //Pretérito imperfecto
								   	    "ondría   ","ondrías  ","ondría   ","ondríamos","ondrían  ","ondrían  "}; //Condicional
enBasePronombres DesinenciaCompuestaPoner={ "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  ", //Pretérito Perfecto Compuesto
									        "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  ", //Pretérito anterior
									        "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  ",  //Futuro Compuesto
									        "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  ",  //Pretérito pluscuamperfecto
									        "uesto  ","uesto  ","uesto  ","uesto  ","uesto  ","uesto  "}; //Condicional
enBasePronombres SubjuntivoSimplePoner={"onga      ","ongas    ","onga     ","ongamos  ","ongan    ","ongan    ", //presente
									    "usiera    ","usieras  ","usiera   ","usiéramos","usieran  ","usieran  ", //pret. imperfecto
									    "usiere    ","usieres  ","usiere   ","usiéremos","usieren  ","usieren  "};//futuro
enBasePronombres DesinenciaOtrosPoner= {"oniendo ","uesto","on tú"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleDiscernir={"ierno     ","iernes    ","ierne     ","ernimos   ","iernen    ","iernen    ", //Presente
								   		    "erní      ","erniste   ","ernió     ","ernimos   ","ernieron  ","ernieron  ", //Pretérito perfecto simple 
								   	        "erniré    ","ernirás   ","ernirá    ","erniremos ","ernirán   ","ernirán   ", //Futuro
								    	    "ernía     ","ernías    ","ernía     ","erníamos  ","ernían    ","ernían    ", //Pretérito imperfecto
								   	        "erniría   ","ernirías  ","erniría   ","erniríamos","ernirían  ","ernirían  "}; //Condicional
enBasePronombres DesinenciaCompuestaDiscernir={ "ernido ","ernido ","ernido ","ernido ","ernido ","ernido ", //Pretérito Perfecto Compuesto
									        	"ernido ","ernido ","ernido ","ernido ","ernido ","ernido ", //Pretérito anterior
									        	"ernido ","ernido ","ernido ","ernido ","ernido ","ernido ",  //Futuro Compuesto
									        	"ernido ","ernido ","ernido ","ernido ","ernido ","ernido ",  //Pretérito pluscuamperfecto
									        	"ernido ","ernido ","ernido ","ernido ","ernido ","ernido "}; //Condicional
enBasePronombres SubjuntivoSimpleDiscernir={"ierna     ","iernas   ","ierna    ","iernamos  ","iernan   ","iernan   ", //presente
									    	"erniera   ","ernieras ","erniera  ","erniéramos","ernieran ","ernieran ", //pret. imperfecto
									    	"erniere   ","ernieres ","erniere  ","erniéremos","ernieren ","ernieren "};//futuro
enBasePronombres DesinenciaOtrosDiscernir= {"erniendo ","ernido","ierne tú"}; //Gerundio, Participio, Imperativo en la 2da persona del singular

enBasePronombres DesinenciaSimpleVenir={"engo     ","ienes    ","iene     ","enimos   ","ienen    ","ienen    ", //Presente
								   		"ine      ","iniste   ","ino      ","inimos   ","inieron  ","inieron  ", //Pretérito perfecto simple 
								   	    "endré    ","endás    ","endrá    ","endremos ","endrán   ","endrán   ", //Futuro
								    	"enía     ","enías    ","enía     ","eníamos  ","enían    ","enían    ", //Pretérito imperfecto
								   	    "endría   ","endrías ","endría  ","endríamos","endrían ","endrían "}; //Condicional
enBasePronombres DesinenciaCompuestaVenir={ "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ", //Pretérito Perfecto Compuesto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ", //Pretérito anterior
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ",  //Futuro Compuesto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  ",  //Pretérito pluscuamperfecto
									        "enido  ","enido  ","enido  ","enido  ","enido  ","enido  "}; //Condicional
enBasePronombres SubjuntivoSimpleVenir={"enga      ","engas    ","enga     ","engamos   ","engan    ","engan    ", //presente
									    "iniera    ","inieras  ","iniera   ","iniéramos ","inieran  ","inieran  ", //pret. imperfecto
									    "iniere    ","inieres  ","iniere   ","iniéremos ","inieren  ","inieren  "};//futuro
enBasePronombres DesinenciaOtrosVenir= {"erniendo ","ernido","ierne tú"}; //Gerundio, Participio, Imperativo en la 2da persona del singular


enBasePronombres Pronombres = {"yo", "tú", "él", "nosotros","ustedes" ,"ellos"};                                                                             
enBasePronombres comp = {"he   ","has  ","ha   ","hemos","han  ","han  ",
						 "hube    ","hubiste ","hubo    ","hubimos ","hubieron","hubieron",
						 "habré   ","habrás  ","habrá   ","habremos","habrán  ","habrán  ",
						 "había   ","habías  ","había   ","habíamos","habían  ","habían  ",
						 "habría   ","habrías  ","habría   ","habríamos","habrían  ","habrían  "};
enBasePronombres Scomp = {"haya   ","hayas  ","haya   ","hayamos","hayan  ","hayan  ",
						  "hubiera   ","hubieras  ","hubiera   ","hubiéramos","hubieran  ","hubieran  ",
						  "hubiere   ","hubieres  ","hubiere   ","hubiéremos","hubieren  ","hubieren  "};

/*Para comparar los caracteres ñ y í fueron remplazados por su equivalente hexadecimal*/
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
char *verbosE[]={"bruñir","engullir","uñir","muñir","bullir","guañir","retiñir","constriñir","gruñir","remullir","zuñir","rebullir","tollir", //12 o 13
      "desgañir","hiñir","escullir","zambullir","fallir","albañir","junir","lullir", // 19 
		  "reír","freír", // 21 
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
 		"Tragar algo precipitadamente, de golpe o sin moderación.",
 		"Juntar dos o más elementos distintos para formar un todo.",
 		"Concertar, disponer o manejar un asunto, especialmente si se hace en interés o provecho propios.",
 		"Producir [un líquido] burbujas que suben desde el interior del mismo y estallan al llegar a la superficie, cuando este alcanza una temperatura determinada, por fermentación o por efervescencia.",
 		"Cerrar y abrir un ojo rápidamente dejando el otro abierto.",
 		"Sonido repetido en los oídos de una campana u otra cosa.",
 		"Forzar a alguien a hacer algo que no quiere.",
 		"Emitir [una persona] sonidos no articulados o palabras murmuradas entre dientes que muestran su enfado o desagrado.",//8
		"Agitarse una cosa dentro de algo.",
		"Reforzar con abrazaderas metálicas.",//10
		"Agitarse una cosa dentro de algo.",
		"Hacer que una persona quede imposibilitada de moverse.",
		"Elegir a alguien o algo para cumplir una tarea.",
		"Insertar una cosa en otra.",
		"Labrar a mano una obra en algún material.",
		"Meter con ímpetu algo o a alguien dentro del agua u otro líquido.",
		"Tener algo un error o una equivocación.",
		"Persona que construye edificios u otras obras.",
		"Atar o sujetar al yugo bueyes, mulas u otras bestias.",
		"Frotar, estregar, rozar algo con otra cosa.",//20
		"Manifestar alegría, placer o felicidad mediante ciertos movimientos de la boca, los ojos y otras partes de la cara, acompañados de la emisión de una serie de sonidos explosivos e inarticulados.",
		"Cocinar un alimento en aceite u otro tipo de grasa hirviendo.",
		"Dar un golpe, un disparo, etc., en el lugar previsto o propuesto o en el punto preciso al que se dirigió.",
		"Hacer que alguien deje de dormir o interrumpir el sueño de alguien.",
		"Razonar con detenimiento sobre un tema, especialmente en público",
		"Hacer que una persona no sepa cómo reaccionar ni qué pensar o decir, generalmente por medio de algo inesperado o sorprendente.",
		"No tener acierto al hacer una cosa o al obrar o actuar de una determinada manera.",
		"Hacer que dos o más cosas armonicen o actúen de forma conjunta.",
		"Cometer un error o equivocarse en cierta cosa.",
		"Extender o estirar una cosa horizontalmente.",
		"Ir de un lugar alto a otro más bajo.",
		"Sobrepasar [una cosa] un determinado límite.",
		"Hacer que una cosa ocupe más espacio del que ocupa, abriéndola, desdoblándola, desenrollándola, etc.",
		"Percibir o notar la idea de un modo preciso y claro en lo que se dice, hace o sucede",
		"Fingir que no se entiende cierta cosa o afectar ignorancia.",
		"Entender algo que no está expreso pero que se supone o se deduce.",
		"Hacer una hendedura",
		"Guardar o proteger contra un ataque, un peligro o un daño.",
		"Percibir y tener una idea clara de lo que se dice, se hace o sucede o descubrir el sentido profundo de algo.",
		"Hacer que prenda una cosa que está especialmente preparada o adaptada para ello, aplicándole fuego o haciendo que el fuego brote de ella.",
		"Entender o interpretar mal una cosa.",
		"Asumir o entender algo que, aunque no está expresado explícitamente, se puede suponer de manera lógica por el contexto.",
		"Entender algo que no está expreso pero que se supone o se deduce.",
		"Luchar entre sí [varias personas, animales o cosas que aspiran a un mismo objetivo o a la superioridad en algo]."
		"Ir de un lugar a otro más alto.",
		"Aplicar voluntariamente la actividad mental o los sentidos a un determinado estímulo u objeto mental o sensible.",
		"Hacer menos tensa o tirante una relación, una situación u otra circunstancia.",
		"Acomodarse o adaptarse [una persona] al gusto y la voluntad de otra.",
		"Inspeccionar, vigilar, gobernar.",
		"Extenderse a la vez que otro.",
		"Tener el deseo, la voluntad o la intención de hacer, poseer o lograr algo.",
		"Tener animadversión hacia una persona.",
		"Querer el bien para los demás.",
		"Dejar de querer.",
		"Indica que lo expresado por el complemento directo tiene una relación, especialmente de posesión, pertenencia o inclusión, con la persona o cosa designada por el sujeto.",
		"Hacer que una persona o una cosa esté en un lugar determinado.",
		"Distinguir por medio del intelecto una cosa de otra o varias cosas entre ellas.",
		"Separar con el cedazo o la criba la parte fina de una materia reducida a polvo de las partes más gruesas.",
		"Decidir la diferencia entre cosas; otorgar un cargo o distinción",
		"Ir hacia el lugar donde está la persona que habla."};
 		
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
  		 "\n(ADVERTENCIA: No atender a esta instrucción ocasionará un resultado inesperado ) \n");  
  
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
  		fprintf(miArchivo,"%s. \nDefinición: %s \n",verbosE[i],definiciones[i]);
  
  if(num==1){
  	/*Conjugar como verbo irregular*/
  	if( 0<=i && i<=19){
  		/*conjugar modelo bruñir*/
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
