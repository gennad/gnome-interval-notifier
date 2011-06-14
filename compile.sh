#g++ -Wall `pkg-config --cflags --libs gtk-2.0` time.cpp -o time -l notify

#gcc test.c -Wall -o test `pkg-config --cflags --libs glib-2.0`

gcc -Wall -o test test.c `pkg-config --libs --cflags glib-2.0 gtk+-2.0` -lnotify

