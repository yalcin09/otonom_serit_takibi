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
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/yalcin/otonom_araba_projesi/src/rosserial/rosserial_arduino"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/yalcin/otonom_araba_projesi/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/yalcin/otonom_araba_projesi/install/lib/python2.7/dist-packages:/home/yalcin/otonom_araba_projesi/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/yalcin/otonom_araba_projesi/build" \
    "/usr/bin/python2" \
    "/home/yalcin/otonom_araba_projesi/src/rosserial/rosserial_arduino/setup.py" \
    build --build-base "/home/yalcin/otonom_araba_projesi/build/rosserial/rosserial_arduino" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/yalcin/otonom_araba_projesi/install" --install-scripts="/home/yalcin/otonom_araba_projesi/install/bin"
