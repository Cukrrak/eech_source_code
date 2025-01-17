#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include <ctype.h>
#include <sys/stat.h>

#define SAFE_FOPEN_RB

#include "ee3dexp.cpp"

#include "../common/common.h"
#include "names.cpp"
#include "textures.cpp"
#include "trans.cpp"
#include "scenes.cpp"
#include "lws_exp.cpp"

int main(void)
{
 puts("Enemy Engaged 3D Exporter build " __DATE__);

 char filename[1024];

 FILE* redirect = freopen("EEEXPLOG.TXT", "w", stdout);

 TexturesFinder textures_finder(*getcwd(filename, sizeof(filename)));
 EET eet(textures_finder);
 const AllNames names(eet);
 const Objects objects;
 const Scenes scenes(objects);
 SimpleTranslator translator;
 LwsExport lwsexp(scenes.GetCameras());

 mkdir("\\TEXTURES");
 TexturesExporter textures;
 textures.export_textures(eet);

 mkdir("_OBJECTS");

 eet.ExportAnimations();

 for (int i = 1; i <= objects.GetNumberOfObjects(); i++)
  {
   const OBJECT_3D& obj = objects.GetObject(i);
   if (obj.surfaces)
    {
     sprintf(filename, "_OBJECTS/%04X.LWO", i);
     ExportLWO(eet, filename, obj);
    }
  }

 for (int i = 1; i <= scenes.GetNumberOfScenes(); i++)
  {
   sprintf(filename, "_OBJECTS/%04X_%s.LWS", i, names.Objects[i]);
   printf("Exporting scene '%s'\n", filename);
   lwsexp.ExportScene(names, translator, filename, scenes.GetScene(i));
  }

 fclose(redirect);

 return 0;
}
