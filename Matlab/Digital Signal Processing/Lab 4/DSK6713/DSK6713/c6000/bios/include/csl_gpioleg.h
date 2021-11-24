#include  <csl_gpio.h>

#if  C64_SUPPORT
#define GPIO_config(config)    GPIO_config(_hGpioDev0,config);
#define GPIO_configArgs( gpgc, gpen,  gpdir, gpval, gphm,  gplm,  gppol)\
        GPIO_configArgs(_hGpioDev0, gpgc, gpen,  gpdir, gpval,   gphm,  gplm,  gppol)
#define GPIO_getConfig(config)  GPIO_getConfig(_hGpioDev0,config)


#define GPIO_pinEnable(pinId)  GPIO_pinEnable(_hGpioDev0,pinId)

#define GPIO_pinDisable(pinId) GPIO_pinDisable(_hGpioDev0, pinId)
#define GPIO_pinDirection(pinId,direction) GPIO_pinDirection(_hGpioDev0,pinId,direction)


#define GPIO_pinRead( pinId) GPIO_pinRead(_hGpioDev0, pinId)

/* For output Pins */
#define GPIO_pinWrite( pinId,  val) GPIO_pinWrite(_hGpioDev0, pinId,  val)


/* For input Pins */
#define GPIO_deltaHighGet( pinId) GPIO_deltaHighGet(_hGpioDev0, pinId)
#define GPIO_deltaHighClear( pinId) GPIO_deltaHighClear(_hGpioDev0, pinId)
#define GPIO_deltaLowGet( pinId) GPIO_deltaLowGet(_hGpioDev0, pinId)
#define GPIO_deltaLowClear( pinId) GPIO_deltaLowClear(_hGpioDev0, pinId)

#define GPIO_maskHighSet( pinId) GPIO_maskHighSet(_hGpioDev0, pinId)
#define GPIO_maskHighClear( pinId) GPIO_maskHighClear(_hGpioDev0, pinId)
#define GPIO_maskLowSet( pinId) GPIO_maskLowSet(_hGpioDev0, pinId)
#define GPIO_maskLowClear( pinId) GPIO_maskLowClear(_hGpioDev0, pinId)

/* Pass Through Mode */
#define GPIO_intPolarity(signal,polarity) GPIO_intPolarity(_hGpioDev0, signal,  polarity)
#endif

