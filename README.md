# eink

** Najpierw sprawdź, jaki masz model wyświetlacza i odpowiednio dostosuj plik library.py poprzez analizę tego, co daje producent danego wyświetlacza eink, o ile w ogóle daje on instrukcję.
W razie czego musisz poprosić mnie o pomoc, żeby to rozwiązać. Całe repo ma możliwość rozbudowy o pliki w Python dla konkretnych wyświetlaczy.

Przykładowe [wyświetlacze eink od waveshare](https://www.waveshare.com/epaper)

Każdy z nich ma na samym dole stronę do WIki, a przynajmniej powinien mieć, gdzie jest przykładowa implementacja.

Ogólne założenia są takie, że czasem ten kod należy poprawić, bo nie zawsze jest on prawidłowo napisany. Stąd po prostu podaj dokładny model wyświetlacza i będzie można napisać to, jak należy.

Wielokrotnie naciąłem się na to, że jakość kodu w C, C++, czy Python w Wiki Waveshare pozostawia wiele do życzenia, a czasem jest to wręcz szkolny problem źle napisanej pętli for. Miałem taki przypadek i w moim innym repo jest kod do waveshare, gdzie poprawiałem pętlę, bo logika pomiaru temperatury była zła.

Generalnie komendą df - kTh wyciągasz dane o użyciu dysku. Możesz użyć awk, sed grep, egrep, gawk z użyciem df lub du i wyrzucać dane do jakiegoś pliku tekstowego.
Potem to musisz zamienić na obrazek i wysłać do eink. Możesz to zrobić w skrypcie Python.

W crontab możesz ustawić, żeby skrypt był wykonywany co kilka minut, lub jaki chcesz interwał czasowy.
To powinno załatwić temat najszybciej. Z grafana jest o tyle łatwiej, że wykresy możesz szybko przerabiać na grafiki i wysyłać do eink,
ale musisz postawić grafana+Telegraf+influxdb albo Prometheus zamiast Telegraf, czyli kombajn. Nie ma to sensu, bo strzelasz wtedy do komara z armaty.
Ewentualnie możesz bashtop, czy glances ogarnąć to tak, aby widok zajętości dysków zrzucał do obrazka. Tak czy siak, sprowadza się to tego,
jak zapisać to, co idzie na standard output do obrazka i wysłać to do eink.

Jak wysłać to na eink. Na przykład tak jak poniżej.

1. Zidentyfikuj swój model ekranu e-ink
- Określ dokładny model i markę swojego wyświetlacza e-ink. Jest to kluczowe, ponieważ różne modele mają różne biblioteki lub API.
2. Zainstaluj bibliotekę dla swojego wyświetlacza e-ink
- Większość wyświetlaczy e-ink dla Raspberry Pi lub podobnych systemów ma biblioteki Pythona. Można je zazwyczaj znaleźć na GitHubie lub na stronie producenta.
- Zainstaluj bibliotekę za pomocą pip lub postępuj zgodnie z instrukcjami instalacji podanymi przez producenta.
3. Zaimportuj bibliotekę w swoim skrypcie Pythona
- W swoim skrypcie Pythona zaimportuj niezbędne moduły z biblioteki.
4. Zainicjuj wyświetlacz
- Użyj funkcji biblioteki do zainicjowania wyświetlacza e-ink.
5. Załaduj i wyślij obraz na wyświetlacz
- Załaduj obraz, który stworzyłeś z informacjami o użyciu dysku.
- Użyj funkcji dostarczonych przez bibliotekę, aby wyświetlić obraz na ekranie e-ink. Zazwyczaj wymaga to konwersji obrazu na format kompatybilny z wyświetlaczem e-ink, a następnie wysłania go na wyświetlacz.
6. Odśwież wyświetlacz
- Wyświetlacze e-ink często wymagają polecenia odświeżenia, aby zaktualizować wyświetlany obraz.

Uwaga: Zamień 'eink_library' i metody takie jak 'EInkDisplay', 'convert_image', 'display_image' i 'refresh' na rzeczywiste biblioteki i metody używane dla Twojego konkretnego modelu wyświetlacza e-ink.
Jeśli podasz dokładny model swojego wyświetlacza e-ink, mogę dać Ci bardziej szczegółowe wskazówki dostosowane do tego modelu.

Temat załatwia crontab. Jak nie ogarniasz to popatrz na [crontab guru](https://crontab.guru/). Odpalasz skrypt jeden po drugim w odstępie minuty. Jeden zbiera stan dysku, drugi wysyła na eink. To rozwiązuje cały Twój problem.
