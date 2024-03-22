#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/qin/M300_ws/src/arduino_actuator"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/qin/M300_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/qin/M300_ws/install/lib/python3/dist-packages:/home/qin/M300_ws/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/qin/M300_ws/build" \
    "/usr/bin/python3" \
    "/home/qin/M300_ws/src/arduino_actuator/setup.py" \
     \
    build --build-base "/home/qin/M300_ws/build/arduino_actuator" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/qin/M300_ws/install" --install-scripts="/home/qin/M300_ws/install/bin"
