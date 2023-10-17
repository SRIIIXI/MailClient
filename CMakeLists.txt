cmake_minimum_required(VERSION 3.1.0)

project(MailClient)

include_directories(./include/ /include/ /usr/include/ /usr/local/include/ /usr/include/openssl/)
link_directories(./lib/ /lib /usr/lib/ /usr/local/lib/)

link_libraries(dl rt pthread ssl crypto)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(project_sources 
./sources/Network.cpp
./sources/Mail.cpp
./sources/ImapClient.cpp
./sources/SmtpClient.cpp
./sources/TcpClient.cpp
./sources/Base64.cpp
./sources/Configuration.cpp
./sources/DateTime.cpp
./sources/Directory.cpp
./sources/Logger.cpp
./sources/SignalHandler.cpp
./sources/StringEx.cpp
./sources/MailStorage.cpp
./sources/ContactDatabase.cpp
./sources/MailDatabase.cpp
./sources/ThemeHandler.cpp
./sources/VerticalLine.cpp
./sources/HorizontalLine.cpp
./sources/RichDataList.cpp
./sources/PictureBox.cpp
./sources/ActionBuilder.cpp
./sources/Calender.cpp
./sources/DirectoryView.cpp
./sources/About.cpp
./sources/MailBoxView.cpp
./sources/MailComposer.cpp
./sources/MailView.cpp
./sources/MainWindow.cpp
./sources/ProfileView.cpp
./sources/SettingsView.cpp
./sources/ContactsView.cpp
./sources/ContactDetails.cpp
./sources/AddressBookWindow.cpp
./sources/Tasks.cpp
./sources/MailClient.cpp
./sources/main.cpp
)

set(project_headers 
./include/Network.h
./include/SecurityType.h
./include/Mail.h
./include/ImapClient.h
./include/SmtpClient.h
./include/TcpClient.h
./include/Base64.h
./include/Configuration.h
./include/DateTime.h
./include/Directory.h
./include/Logger.h
./include/SignalHandler.h
./include/StringEx.h
./include/MailStorage.h
./include/ContactDatabase.h
./include/MailDatabase.h
./include/Profile.h
./include/Contact.h
./include/ThemeHandler.h
./include/VerticalLine.h
./include/HorizontalLine.h
./include/RichDataList.h
./include/PictureBox.h
./include/ActionBuilder.h
./include/Calender.h
./include/DirectoryView.h
./include/About.h
./include/MailBoxView.h
./include/MailComposer.h
./include/MailView.h
./include/MainWindow.h
./include/ProfileView.h
./include/SettingsView.h
./include/ContactsView.h
./include/ContactDetails.h
./include/AddressBookWindow.h
./include/Tasks.h
./include/MailClient.h
)

set(project_resources 
./resources/Resources.qrc
)

add_executable(MailClient ${project_sources} ${project_headers} ${project_resources})
link_libraries(rt pthread dl)

target_link_libraries(MailClient Qt6::Widgets Qt6::Core)
