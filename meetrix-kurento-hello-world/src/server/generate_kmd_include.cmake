  execute_process (COMMAND /usr/bin/kurento-module-creator -r /tmp/meetrix-kurento-hello-world/src/server/interface ;-dr;/usr/share/kurento/modules -o /tmp/meetrix-kurento-hello-world/src/server/)

  file (READ /tmp/meetrix-kurento-hello-world/src/server/meetrixkurentohelloworld.kmd.json KMD_DATA)

  string (REGEX REPLACE "\n *" "" KMD_DATA ${KMD_DATA})
  string (REPLACE "\"" "\\\"" KMD_DATA ${KMD_DATA})
  string (REPLACE "\\n" "\\\\n" KMD_DATA ${KMD_DATA})
  set (KMD_DATA "\"${KMD_DATA}\"")

  file (WRITE /tmp/meetrix-kurento-hello-world/src/server/meetrixkurentohelloworld.kmd.json ${KMD_DATA})
