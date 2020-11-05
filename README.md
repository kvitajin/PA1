# 460-4117/01 – Paralelní algoritmy I (PA I)   
| | | | | 
|-|-|-|-|
|**Garantující katedra**|Katedra informatiky| **Kredity**|	4 |    
|**Garant předmětu**|doc. Ing. Pavel Krömer, Ph.D.|**Garant verze předmětu**|	doc. Ing. Pavel Krömer, Ph.D. |   
|**Úroveň studia**| pregraduální nebo graduální  | | |  
|**Jazyk výuky** | čeština  | | |  
|**Rok zavedení**|2015/2016| **Rok zrušení**	  | |
|**Určeno pro fakulty** |	FEI| **Určeno pro typy studia**|	navazující magisterské |

### Výuku zajišťuje
  
|Os. čís.| Jméno             |	Cvičící|	Přednášející|  
|--------|-------------------|---------|----------------|
|BAT0014 | 	Ing. Tarek Batiha| [x]    | [ ]|
|KRO080| 	doc. Ing. Pavel Krömer, Ph.D.| [x]     | [x]|
  

### Rozsah výuky pro formy studia
|Forma studia|	Zp.zak.|Rozsah|
|------------|---------|------|
|prezenční| 	Klasifikovaný zápočet| 	2+2
|kombinovaná| 	Klasifikovaný zápočet| 	10+0

### Cíle předmětu vyjádřené dosaženými dovednostmi a kompetencemi
Přehled v oblasti návrhu, realizace a hodnocení paralelních algoritmů. Praktické osvojení paralelních programovacích technik pro vybrané paralelní architektury. Pracovní znalosti v oblasti paralelních systémů a jejich programování, zejména: samostatný návrh paralelních algoritmů, resp. paralelizace sekvenčních algoritmů. Praktická realizace paralelního algoritmu na bázi modelu předávání zpráv. Analýza algoritmu a vyhodnocení implementace. Optimalizace a zvyšování efektivity.

### Vyučovací metody
Přednášky
Cvičení (v učebně)  
### Anotace
Kurz poskytne posluchačům základy pro aktivní práci v oblasti paralelních systémů, algoritmů a programování. Zaměřuje se na praktickou tvorbu programů, aby byli s to využít dnešní výkonnou výpočetní techniku, od paralelních superpočítačů s distribuovanou pamětí přes vícejádrové procesory až po výpočetní akcelerátory a univerzální grafické karty, pro řešení výpočetně náročných úloh z různých aplikačních oblastí.
  
Důraz je kladen jak na seznámení se se standardními paralelními paradigmaty, rozhraními, jazyky a knihovnami, tak na reflexi aktuálního vývoje v této oblast prostřednictvím představení nejnovějších paralelních platforem a prostředí. Posluchač bude seznámen s tvorbou paralelních aplikací prostřednictvím modelu předávání zpráv (multipočítačů), s programování systémů se sdílenou pamětí (symetrických multiprocesorů) a programováním výpočetních akcelerátorů. Diskutovány však budou také cloudové platformy, model map-reduce nebo paralelní Matlab.
  
Cvičení budou věnována praktickému návrhu paralelních algoritmů a jejich implementaci v prostředí MPI, OpenMP, UPC, CUDA-C nebo v paralelním Matlabu.

### Povinná literatura:
1. Sylaby k předmětu Paralelní algoritmy I.
2. Introduction to Parallel Computing (2nd Edition). Ananth Grama, George Karypis, Vipin Kumar, Anshul Gupta, Addison-Wesley, 2003
3. Using OpenMP: Portable Shared Memory Parallel Programming, Volume 10, Barbara Chapman, Gabriele Jost, Ruud van der Pas, MIT Press, 2008

### Doporučená literatura:
1. Distributed Computing Principles, Algorithms, and Systems, Ajay D. Kshemkalyani, Mukesh Singhal, Cambridge, 2008
2. Distributed Systems: Principles and Paradigms, Andrew S. Tanenbaum, Maarten van Steen, Pearson Prentice Hall, 2007
3. Patterns for parallel programming. Timothy Mattson, Beverly Sanders, Berna Massingill, Addison-Wesley, 2004  
### Forma způsobu ověření studijních výsledků a další požadavky na studenta  
Posluchači během semestru vypracují tři domácí úkoly na přidělená témata z oblasti paralelních algoritmů. Nabízená témata bude zahrnovat paralelní řešení komplexních problémů a použití různých metod a technik paralelních algoritmů. Na domácích úkolech budou studenti pracovat během semestru průběžně. Řešení bude možno konzultovat s vyučujícím během přednášek, cvičení, během osobních konzultací nebo e-mailem.
### E-learning
### Další požadavky na studenta  
Další požadavky nejsou kladeny.  
### Prerekvizity  

Předmět nemá žádné prerekvizity.   
### Korekvizity

Předmět nemá žádné korekvizity.  
  
### Osnova předmětu  
#### Přednášky:
==========
1. Úvod do problematiky programování paralelních aplikací. Procesy a vlákna. Procesy a vlákna z pohledu operačního systému. SIMD a FMA instrukce moderních procesorů.

2. Sekvenční vs. paralelní programování. Úskalí paralelního programování. Uváznutí (definice, vlastnosti, podmínky, detekce, eliminace). 

3. Paralelní vs. distribuované aplikace. Klasifikace paralelních platforem. Systémy se sdílenou a distribuovanou pamětí. Flynnova taxonomie. 

4. Programování systémů se sdílenou pamětí. Programování s pomocí vláken. Knihovna pthreads. Vlákna v jazycích Java a C#. Synchronizace a vyloučení, uváznutí. 

5. Rozhraní OpenMP. Podpora OpenMP v překladačích. Direktivy a funkce OpenMP. Redukce v OpenMP. 

6. Model Fork-Join. Programovací jazyky Cilk a Cilk++. Paralelní Matlab. Paralelní programování v Pythonu, knihovna NumPy.

7. Programování systémů s distribuovanou pamětí. Komunikace pomocí zasílání zpráv. Posix fronty, sockety. Rozhraní MPI, základní funkce MPI. MPI knihovny. 

8. Model Partitioned Global Address Space (PGAS). Programovací jazyk Unified Parallel C (UPC). 

9. Dávkové (neinteraktivní) spouštění distribuovaných úloh. Plánovače PBSPro a Torque.

10. Programování  v prostředí gridu a cloudu. Webové služby, distribuované aplikace s využitím webových služeb. Paradigma Map-Reduce, framework Hadoop.

11. Úvod do programování akcelerátorů. Architektura GPGPU (organizace programu, organizace paměti). Datový paralelismus. Prostředí  CUDA a jazyk CUDA-C. 

12. Další rozhraní pro programování akcelerátorú: OpenCL, OpenACC, OpenMP 4.

13. Architektura Intel MIC. Způsoby programování MIC a Xeon Phi. Nové a vznikající platformy. 

14. Hybridní paralelní aplikace. Programování pomocí MPI-OpenMP, hybridní CPU-GPU architektury.

#### Cvičení:
========
Obsah cvičení a procvičované úlohy budou korespondovat s látkou probíranou na přednáškách:

1. Přehled prostředí pro tvorbu paralelních aplikací. SIMD instrukce.

2. Implementace jednoduchého programu s více vlákny.

3. Implementace jednoduchého programu ve více procesech. Komunikace pomocí socketů a front.

4. Debugging a profilování paralelních programů.

5. Implementace jednoduchého programu za pomoci OpenMP. Paralelizace sekvenčního programu pomocí OpenMP.

6. Implementace jednoduchého programu v jazyce Cilk++. Příklad paralelního programování v Matlabu.

7. Implementace jednoduchého programu pomocí rozhraní MPI. 

8. Implementace jednoduchého programu v jazyce UPC.

9. Použití plánovačů PBS, PBSPro a Torque, příkaz qsub a QSUB direktivy.

10. Implementace jednoduchého map-reduce programu ve frameworku Hadoop.

11. Implementace jednoduchého data-paralelního programu v CUDA-C.

12. Příklady použití OpenCL, OpenACC a OpenMP 4.

13. Programování Intel MIC. Implementace jednoduchého programu pro Intel MIC.

14. Implementace jednoduchého hybridního programu pomocí MPI a OpenMP. 
