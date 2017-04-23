#ifndef _KINDS_H_
#define _KINDS_H_

#include <string>

#include "EObject.h"

class RenderObject : public EObject
{
private:
	std::string oName;
	std::string oTag;
	std::string oLayer;
	bool oActive;
public:
	RenderObject() : EObject() {}
	~RenderObject(){}

	virtual inline void setName(const std::string &name) {
		oName = name;
	}
	virtual inline void setTag(const std::string &tag) {
		oTag = tag;
	}
	virtual inline void setLayer(const std::string &layer) {
		oLayer = layer;
	}
	virtual inline void setActive(bool t){
		oActive = t;
	}

	virtual std::string &getName() {
		return oName;
	}
	virtual std::string &getTag(){
		return oTag;
	}
	virtual std::string &getLayer() {
		return oLayer;
	}
	virtual bool activeSelf() {
		return oActive;
	}
};


#endif //_KINDS_H_