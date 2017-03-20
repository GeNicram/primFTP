# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = primFTP

QMAKE_CXXFLAGS+= -std=c++0x

CONFIG += sailfishapp

SOURCES += src/primFTP.cpp \
    src/browser.cpp \
    src/storage.cpp \
    src/ftprecord.cpp

OTHER_FILES += qml/primFTP.qml \
    qml/cover/CoverPage.qml \
    rpm/primFTP.spec \
    rpm/primFTP.yaml \
    translations/*.ts \
    primFTP.desktop \
    rpm/primFTP.changes.in \
    LICENSE.primFTP

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/primFTP-de.ts

HEADERS += \
    src/browser.h \
    src/storage.h \
    src/ftprecord.h

DISTFILES += \
    qml/pages/DirectoryContent.qml \
    qml/pages/MainMenu.qml \
    qml/pages/ServerSettings.qml

