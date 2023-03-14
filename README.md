# Ardupilot (MAO VTOL)
This repo is a fork of ardupilot to add support for the MAO VTOL airframe
This repo was created on the 14th of March 2023, the current version of arduplane being Plane 4.3.2
The changes made to the original ardupilot codebase can be viewed by comparing the commits made by JacquesWelgemoed to the MAO_VTOL branch with the main branch.

To build this version of the firmware follow these steps: (This guide assumes you are using an ubuntu installation for your build environment)

**Clone this repository**
```
git clone https://github.com/JacquesWelgemoed/ardupilot
cd ardupilot
git submodule update --init --recursive
```

**Install additional required packages**
```
cd ardupilot
Tools/environment_install/install-prereqs-ubuntu.sh -y
```
**Reload the path (log-out and log-in to make permanent):**
```
. ~/.profile
```

**After these steps we clean the build environment by using**
```
cd ardupilot
./waf configure
./waf clean
```

**The next step is to configure the board target for your firmware build (e.g. Cube Orange, Cube Black, etc.) To see the possible board targets use**
```
./waf list_boards
```

**If, for example, we are building the firmware for a Cube Black, the following command will congfigure the build environment for that target:**
```
./waf configure --board CubeBlack
```

**You are now ready to build the code, since the MAO VTOL is a tiltrotor we need to build Plane using the following command:**
```
./waf plane
```

**Please note all build commands should be run from the root of the ardupilot directory, wherever you cloned that to.**

*This repo contains a temporary fix in the lbraries/AP_GPS/AP_GPS_NMEA.cpp file in lines 779 & 781 to force the pragma statement to run by commenting out the if statement since building was failing with the current ardupilot master*
