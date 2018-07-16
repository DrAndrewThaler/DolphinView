# DolphinView
A LiDAR system to convert distance measurements into signal pulses in bone-conducting headphones. 

## Background

Dolphin's echolocate but they don't hear those pings quite the way we would. They recieve echolocation pings as vibrations in their lower jaw. Some big whales do this too. Which rasises the question: "what if we could use bone conducting headphones and ultrasonic range finders to mimic that experience?"

And DolphinView was born. 

Ultrasonic rangefinders (at lease the readily available ones use for proximity detection) are really short range (less than half a meter). I replaced those with a much longer range time-of-flight LiDAR unit. It's the kind of thing you might see on a drone to detect and avoid onstacles. Using this LiDAR unit, I created a system that pulses like SONAR the closer an object gets to you. 

But that's just a proximity alarm. The real trick is sending the signal to your brain the way a dolphin might. 

Which brings me to bone conducting headphones. Rather than a tiny speaker sitting in or on your ear, bone conducting headphones sit on you temples and send vibrations directly into you inner ear. Functionally, this means you can listen to music or podcasts at any volume and still hear the world around you. For DolphinView, this means you get a continuous pulse that increases or decrease in frequency (frequency of occurrence, not frequency of the pulse tone) the closer you get to an object. 

This was conceived as an educational project to let students experience the world "like a dolphin might". Several individuals have pointed out that it may have utility for he vision impaired. While that may be true, it certainly would need a lot more refining before anyone should view this as more than a novelty. 

## Bill of Materials
The following list reflects the original sourcing for this project, not necessarily the best or least expensive sourcing. I use Amazon affiliate links to help offset the cost of these builds. If you value this and other projects like it, please consider purchasing parts through these links. 
- [TFMini Time-of-flight range-finding sensor](https://amzn.to/2LhzF03)
- [Bone Conduction Headphones](https://amzn.to/2upeIqk)
- [Arduino UNO](https://amzn.to/2urECKf)
- [Digital Audio Amplifier](https://amzn.to/2uun3sM)
- [3.5mm Stereo Female terminal block](https://amzn.to/2mmyOgF)
- [Push Button Switch](https://amzn.to/2NXeVZQ)
- [Lithium Battery Charger Board](https://amzn.to/2JsXNrP)
- [Adjustable Step-up Converter](https://amzn.to/2Jq3iHC)
- [Pigtail male barrel plug](https://amzn.to/2zLcsic)
- [Lithium Ion Battery 3.7v](https://amzn.to/2JpkPzv)

## Arduino Software and Libraries
This system uses standard Arduino libraries plus the specific library for the TFMini LiDAR Unit.
- [SoftwareSerial.h](https://www.arduino.cc/en/Reference/softwareSerial)
- [TFMini.h](https://github.com/opensensinglab/tfmini)
- [dolphinview.ino](https://github.com/SouthernFriedScientist/DolphinView/blob/master/code/dolphinview.ino)

## Basic Construction
**1. Build the charging circuit:** Remove the connector from the LiPo battery and solder it directly to the B+ and B- terminals of the charging unit. Connect OUT+ and OUT- of the charging unit to IN+ and IN- of the step-up converter. Using a multimeter, adjust the converter output to 5V. solder the 5.5mm barrel plug to the OUT+ and OUT- terminals on the converter. Connect barrel plug to Arduino to confirm power. Solder toggle switch between covnerter and barrel plug on the + line.

**2. Build the amplifier:** Solder wire into Power + and -, Input G and R, and Rout + and - on the Audio Amplifier. Connect Power + and - to GND and 5V on Arduino. Connect Input R to Pin 3 and Input G to GND on the Arduino. Connect Rout - to S and Rout+ to T on the stereo terminal block. Bridge R and T on the terminal block. 

**3. Connect the LiDAR:** Remove the connector and solder on long leads to each of the four wires. Connect negativeand positive terminals to 3.3V and GND on the Arduino. Connect TX to Arduino pin 10 and RX to Arduino pin 11. 

**4. Enclose the system:** Build your own enclosure or use the included laser cutting file to enclose all the components. Attach the LiDAR sensor to the included glasses if you also want to look ridiculous while walking around with this. 

If you build one, please let me know on [Twitter](https://twitter.com/DrAndrewThaler), [Mastodon](https://oceansocial.us/@DrAndrewThaler), or [Instagram](https://www.instagram.com/drandrewthaler/) and tell me how it goes. To support more weird and wonderful projects like this, please check out my [Patreon](https://www.patreon.com/Andrew_Thaler).
