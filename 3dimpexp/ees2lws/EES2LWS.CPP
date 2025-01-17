#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include <ctype.h>
#include <sys/stat.h>

#define SAFE_FOPEN_RB

#include "../common/common.h"
#include "../ee_exp/ee3dexp.cpp"
#include "../ee_exp/names.cpp"
#include "../ee_exp/trans.cpp"
#include "../ee_exp/scenes.cpp"
#include "../ee_exp/lws_exp.cpp"
#include "ees2lws.h"

int main(int argc, char* argv[])
{
 puts("Enemy Engaged EES to LWS converter build " __DATE__);

 if (argc < 3)
  {
   printf("Usage: ees2lws file_name.ees file_name.lws");
   return -1;
  }

 char filename[1024];

 TexturesFinder textures_finder(*getcwd(filename, sizeof(filename)));
 EET eet(textures_finder);
 AllNames names(eet);
 Cameras cameras;
 SimpleAggTranslator translator;
 translator("");
 const Scene scene(argv[1], names, cameras, translator);
 LwsExport exporter(cameras);
 exporter.ExportScene(names, translator, argv[2], scene);

 return 0;
}
