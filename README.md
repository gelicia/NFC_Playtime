NFC_Playtime
============

Little NFC programs


I'll reorganize this later when I have more than one program in here.

This is using the NFC library here - https://github.com/elechouse/PN532

NFC_Playtime.ino is meant to run on a Bean - https://punchthrough.com/bean/
The wiring goes 
- SCL on the antenna to A1 on the Bean 
- SDA on the antenna to A0 on the Bean

The Bean uses it's coin battery to power itself, the antenna is powered by a AAA battery with a DC-DC step up module to make the 1.5V to 5V

Don't forget to connect all the grounds together!

It makes the light red if nothing is detected, blue if a tag is detected but not the right one, and green if the right tag is detected (as defined on the myuid variable).

It does seem to time out after a while, but I think thats a library thing that I'll have to figure out eventually.

A video of this is here https://www.dropbox.com/s/qv3t3m275ax466p/MOV_3281.MOV?dl=0