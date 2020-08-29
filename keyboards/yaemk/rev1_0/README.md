# YAEMK rev 1.0

**Zitat aus Discord Chat von KarlK90 am 06.08.2020**

> ## KarlK9006.08.2020
>
> https://github.com/KarlK90/qmk_firmware/tree/yaemk
>
> *[*20:07*]* hier ist der aktuelle stand der firmware manches ist noch nicht fertig entwickelt
>
> *[*20:08*]* keyboards/yaemk(Bearbeitet)
>
> *[*20:08*]* da sind die ganze config files für das board
>
> *[*20:09*]* unter rev1_0 sind die spezifischen files für eure revision
>
> *[*20:10*]* wenn ihr qmk eingerichtet habt könnt ihr mit dem befehl `qmk flash -kb yaemk/rev1_0 -km via` die firmware flashen(Bearbeitet)
>
> *[*20:10*]* falls ihr den bootloader zerschießt müsst ihr den neu per stlink und openocd flashen
>
> *[*20:11*]* oder ihr nemt probe.rs
>
> *[*20:11*]* dann heißt der befehl `cargo flash --chip STM32F103CB --elf generic_boot20_pb5.elf`
>
> -> [generic_boot20_pb5.elf](./generic_boot20_pb5.elf)
>
> *[*20:12*]*der bootloader ist dieser https://github.com/rogerclarkmelbourne/STM32duino-bootloader

