import os

result = [os.path.join(dp, f) for dp, dn, filenames in os.walk("build/temp.iphoneos-arm64-3.8") for f in filenames if os.path.splitext(f)[1] == '.o']

for file in result:
  path = file.replace("build/temp.iphoneos-arm64-3.8/statsmodels/", "")
  cmd = os.environ["CC"]+" "+os.environ["LDFLAGS"]+" -undefined dynamic_lookup -bundle 'build/temp.iphoneos-arm64-3.8/statsmodels/"+path+"' -o "+"'build/lib.iphoneos-arm64-3.8/statsmodels/"+path.replace(".o", ".cpython-38-darwin.so")+"'"
  print(cmd)
  os.system(cmd)
