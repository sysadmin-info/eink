# eink
Generalnie komendą df - kTh wyciągasz dane o użyciu dysku. Możesz użyć awk, sed grep, egrep, gawk z użyciem df lub du i wyrzucać dane do jakiegoś pliku tekstowego. 
Potem to musisz zamienić na obrazek i wysłać do eink. Możesz to zrobić w skrypcie Python. 

W crontab możesz ustawić, żeby skrypt był wykonywany co kilka minut, lub jaki chcesz interwał czasowy. 
To powinno załatwić temat najszybciej. Z grafana jest o tyle łatwiej, że wykresy możesz szybko przerabiać na grafiki i wysyłać do eink, 
ale musisz postawić grafana+Telegraf+influxdb albo Prometheus zamiast Telegraf, czyli kombajn. Nie ma to sensu, bo strzelasz wtedy do komara z armaty. 
Ewentualnie możesz bashtop, czy glances ogarnąć to tak, aby widok zajętości dysków zrzucał do obrazka. Tak czy siak, sprowadza się to tego, 
jak zapisać to co idzie na standard output do obrazka i wysłać do do eink. 
