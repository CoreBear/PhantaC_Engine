#ifndef _GLOBAL_TOOLS_H
#define _GLOBAL_TOOLS_H

template<typename Generic> void AddObjectToContainer(std::vector<Generic>* container, Generic object) { container->push_back(object); }
template<typename Generic> void RemoveObjectFromContainer(std::vector<Generic>* container, Generic object) { container->erase(std::remove(container->begin(), container->end(), object), container->end()); }

#endif