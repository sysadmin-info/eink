# eink
Generalnie komendą df - kTh wyciągasz dane o użyciu dysku. Możesz użyć awk, sed grep, egrep, gawk z użyciem df lub du i wyrzucać dane do jakiegoś pliku tekstowego. 
Potem to musisz zamienić na obrazek i wysłać do eink. Możesz to zrobić w skrypcie Python. 

W crontab możesz ustawić, żeby skrypt był wykonywany co kilka minut, lub jaki chcesz interwał czasowy. 
To powinno załatwić temat najszybciej. Z grafana jest o tyle łatwiej, że wykresy możesz szybko przerabiać na grafiki i wysyłać do eink, 
ale musisz postawić grafana+Telegraf+influxdb albo Prometheus zamiast Telegraf, czyli kombajn. Nie ma to sensu, bo strzelasz wtedy do komara z armaty. 
Ewentualnie możesz bashtop, czy glances ogarnąć to tak, aby widok zajętości dysków zrzucał do obrazka. Tak czy siak, sprowadza się to tego, 
jak zapisać to co idzie na standard output do obrazka i wysłać do do eink.

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

 
