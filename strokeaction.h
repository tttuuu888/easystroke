#ifndef __STROKEACTION_H__
#define __STROKEACTION_H__
#include "stroke.h"
#include "var.h"


class StrokeAction : private VarI<boost::shared_ptr<sigc::slot<void, RStroke> > > {
	typedef boost::shared_ptr<sigc::slot<void, RStroke> > SA;
public:
	operator bool() {
		return get();
	}
	bool operator()(RStroke stroke) {
		Atomic a;
		if (!get())
			return false;
		(*ref(a))(stroke);
		erase();
		return true;
	}

	void erase() {
		set(SA());
	}

	void set2(sigc::slot<void, RStroke> f) {
		set(SA(new sigc::slot<void, RStroke>(f)));
	}
};

extern StrokeAction stroke_action;

#endif
