# ofxMetaballs is an addon for [openFrameworks](http://openframeworks.cc/)

It's still heavily a work in progress, as it consists of two completely separate implementations that are only informally linked. In the future they should either extend a base class or be modes of a single class. There are also some slight differences in the way MC handles minRadius/maxRadius compared to MT.

The primary differences between MT and MC are:

* MT can always be 3d printed, while MC isn't always manifold or even oriented uniformly.
* MC is generally faster than MT.
* MC internally uses a -1 to +1 domain, while MT uses 0 to 1, but generally shouldn't be an issue for the user as all data should be normalized to 0 to 1 before being fed into MC/MT.