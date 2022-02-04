#pragma once

#include "BunBuiltinNames.h"
#include "BunClientData.h"
#include "root.h"

namespace Zig {

class Path : public JSC::JSNonFinalObject {
  using Base = JSC::JSNonFinalObject;

    public:
  Path(JSC::VM &vm, JSC::Structure *structure, bool isWindows_) : Base(vm, structure) {
    isWindows = isWindows_;
  }

  DECLARE_INFO;

  static constexpr unsigned StructureFlags = Base::StructureFlags;

  template <typename CellType, JSC::SubspaceAccess>
  static JSC::CompleteSubspace *subspaceFor(JSC::VM &vm) {
    return &vm.cellSpace;
  }

  static JSC::Structure *createStructure(JSC::VM &vm, JSC::JSGlobalObject *globalObject,
                                         JSC::JSValue prototype) {
    return JSC::Structure::create(vm, globalObject, prototype,
                                  JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
  }

  static Path *create(JSC::VM &vm, bool isWindows, JSC::Structure *structure) {
    Path *accessor = new (NotNull, JSC::allocateCell<Path>(vm.heap)) Path(vm, structure, isWindows);

    accessor->finishCreation(vm);
    return accessor;
  }
  bool isWindows = false;

  void finishCreation(JSC::VM &vm);
};

} // namespace Zig