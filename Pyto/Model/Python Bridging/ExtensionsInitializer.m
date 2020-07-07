//
//  ExtensionsInitializer.m
//  Pyto
//
//  Created by Adrian Labbé on 03-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Extensions.h"

@interface ExtensionsInitializer: NSObject {
}
@end

@implementation ExtensionsInitializer

-(void) initialize_pil {
    init_pil();
}

#if MAIN
-(void) initialize_lxml {
    init_lxml();
}

-(void) initialize_scipy {
    init_scipy();
}

-(void) initialize_sklearn {
    init_sklearn();
}

-(void) initialize_skimage {
    init_skimage();
}

-(void) initialize_numpy {
    init_numpy();
}

-(void) initialize_cffi {
    init_cffi();
}

-(void) initialize_bcrypt {
    init_bcrypt();
}

-(void) initialize_pywt {
    init_pywt();
}

-(void) initialize_statsmodels {
    init_statsmodels();
}

-(void) initialize_zmq {
    init_zmq();
}

-(void) initialize_gensim {
    init_gensim();
}

-(void) initialize_regex {
    init_regex();
}

-(void) initialize_astropy {
    init_astropy();
}

-(void) initialize_emd {
    init_emd();
}

-(void) initialize_cv2 {
    init_cv2();
}

-(void) initialize_nacl {
    init_nacl();
}

-(void) initialize_matplotlib {
    init_matplotlib();
}

-(void) initialize_pandas {
    init_pandas();
}

-(void) initialize_biopython {
    init_biopython();
}
#endif
@end
