//
//  Extensions.h
//  Pyto
//
//  Created by Adrian Labbé on 03-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

#if !(TARGET_IPHONE_SIMULATOR)
void init_pil(void);
#if MAIN
void init_lxml(void);
void init_scipy(void);
void init_sklearn(void);
void init_skimage(void);
void init_numpy(void);
void init_cffi(void);
void init_bcrypt(void);
void init_pywt(void);
void init_statsmodels(void);
void init_zmq(void);
void init_gensim(void);
void init_regex(void);
void init_astropy(void);
void init_emd(void);
void init_cv2(void);
void init_nacl(void);
void init_matplotlib(void);
void init_pandas(void);
void init_biopython(void);
#endif
#endif
