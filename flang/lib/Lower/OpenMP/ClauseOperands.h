//===-- Lower/OpenMP/ClauseOperands.h ---------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Coding style: https://mlir.llvm.org/getting_started/DeveloperGuide/
//
//===----------------------------------------------------------------------===//

#ifndef FORTRAN_LOWER_OPENMP_CLAUSEOPERANDS_H
#define FORTRAN_LOWER_OPENMP_CLAUSEOPERANDS_H

#include "Utils.h"
#include "mlir/Dialect/OpenMP/OpenMPDialect.h"
#include <optional>

namespace Fortran {
namespace semantics {
class Symbol;
} // namespace semantics
} // namespace Fortran

// TODO Remove Fortran references, move header to MLIR.

namespace Fortran {
namespace lower {
namespace omp {

//===----------------------------------------------------------------------===//
// Mixin structures defining MLIR operands associated with each OpenMP clause.
//===----------------------------------------------------------------------===//

struct AlignedClauseOps {
  llvm::SmallVector<mlir::Value> alignedVars;
  llvm::SmallVector<mlir::Attribute> alignmentAttrs;
};

struct AllocateClauseOps {
  llvm::SmallVector<mlir::Value> allocatorVars, allocateVars;
};

struct CollapseClauseOps {
  llvm::SmallVector<mlir::Value> loopLBVar, loopUBVar, loopStepVar;
  llvm::SmallVector<const Fortran::semantics::Symbol *> loopIV;
};

struct CopyprivateClauseOps {
  llvm::SmallVector<mlir::Value> copyprivateVars;
  llvm::SmallVector<mlir::Attribute> copyprivateFuncs;
};

struct DependClauseOps {
  llvm::SmallVector<mlir::Attribute> dependTypeAttrs;
  llvm::SmallVector<mlir::Value> dependVars;
};

struct DeviceClauseOps {
  mlir::Value deviceVar;
};

struct DeviceTypeClauseOps {
  mlir::omp::DeclareTargetDeviceType deviceType;
};

struct DistScheduleClauseOps {
  mlir::UnitAttr distScheduleStaticAttr;
  mlir::Value distScheduleChunkSizeVar;
};

struct EnterLinkToClauseOps {
  llvm::SmallVector<DeclareTargetCapturePair> symbolAndClause;
};

struct FinalClauseOps {
  mlir::Value finalVar;
};

struct GrainsizeClauseOps {
  mlir::Value grainsizeVar;
};

struct HintClauseOps {
  mlir::IntegerAttr hintAttr;
};

struct IfClauseOps {
  mlir::Value ifVar;
};

struct InReductionClauseOps {
  llvm::SmallVector<mlir::Value> inReductionVars;
  llvm::SmallVector<mlir::Type> inReductionTypes;
  llvm::SmallVector<mlir::Attribute> inReductionDeclSymbols;
  std::optional<llvm::SmallVector<const Fortran::semantics::Symbol *>>
      inReductionSymbols;
};

struct LinearClauseOps {
  llvm::SmallVector<mlir::Value> linearVars, linearStepVars;
};

// The optional parameters - mapSymTypes, mapSymLocs & mapSymbols are used to
// store the original type, location and Fortran symbol for the map operands.
// They may be used later on to create the block_arguments for some of the
// target directives that require it.
struct MapClauseOps {
  llvm::SmallVector<mlir::Value> mapVars;
  std::optional<llvm::SmallVector<mlir::Type>> mapSymTypes;
  std::optional<llvm::SmallVector<mlir::Location>> mapSymLocs;
  std::optional<llvm::SmallVector<const Fortran::semantics::Symbol *>>
      mapSymbols;
};

struct MergeableClauseOps {
  mlir::UnitAttr mergeableAttr;
};

struct NogroupClauseOps {
  mlir::UnitAttr nogroupAttr;
};

struct NontemporalClauseOps {
  llvm::SmallVector<mlir::Value> nontemporalVars;
};

struct NowaitClauseOps {
  mlir::UnitAttr nowaitAttr;
};

struct NumTasksClauseOps {
  mlir::Value numTasksVar;
};

struct NumTeamsClauseOps {
  mlir::Value numTeamsLowerVar;
  mlir::Value numTeamsUpperVar;
};

struct NumThreadsClauseOps {
  mlir::Value numThreadsVar;
};

struct OrderClauseOps {
  mlir::omp::ClauseOrderKindAttr orderAttr;
};

struct OrderedClauseOps {
  mlir::IntegerAttr orderedAttr;
};

struct ParallelizationLevelClauseOps {
  mlir::UnitAttr parLevelThreadsAttr;
  mlir::UnitAttr parLevelSimdAttr;
};

struct PriorityClauseOps {
  mlir::Value priorityVar;
};

struct PrivateClauseOps {
  // SSA values that correspond to "original" values being privatized.
  // They refer to the SSA value outside the OpenMP region from which a clone is
  // created inside the region.
  llvm::SmallVector<mlir::Value> privateVars;
  // The list of symbols referring to delayed privatizer ops (i.e. `omp.private`
  // ops).
  llvm::SmallVector<mlir::Attribute> privatizers;
  // Fortran symbols corresponding to the above SSA values.
  llvm::SmallVector<const Fortran::semantics::Symbol *> privateSymbols;
};

struct ProcBindClauseOps {
  mlir::omp::ClauseProcBindKindAttr procBindKindAttr;
};

struct ReductionClauseOps {
  llvm::SmallVector<mlir::Value> reductionVars;
  llvm::SmallVector<mlir::Type> reductionTypes;
  llvm::SmallVector<mlir::Attribute> reductionDeclSymbols;
  mlir::UnitAttr reductionByRefAttr;
  std::optional<llvm::SmallVector<const Fortran::semantics::Symbol *>>
      reductionSymbols;
};

struct SafelenClauseOps {
  mlir::IntegerAttr safelenAttr;
};

struct ScheduleClauseOps {
  mlir::omp::ClauseScheduleKindAttr scheduleValAttr;
  mlir::omp::ScheduleModifierAttr scheduleModAttr;
  mlir::Value scheduleChunkVar;
  mlir::UnitAttr scheduleSimdAttr;
};

struct SimdlenClauseOps {
  mlir::IntegerAttr simdlenAttr;
};

struct TargetReductionClauseOps {
  llvm::SmallVector<const Fortran::semantics::Symbol *> targetReductionSymbols;
};

struct TaskReductionClauseOps {
  llvm::SmallVector<mlir::Value> taskReductionVars;
  llvm::SmallVector<mlir::Type> taskReductionTypes;
  llvm::SmallVector<mlir::Attribute> taskReductionDeclSymbols;
  std::optional<llvm::SmallVector<const Fortran::semantics::Symbol *>>
      taskReductionSymbols;
};

struct ThreadLimitClauseOps {
  mlir::Value threadLimitVar;
};

struct UntiedClauseOps {
  mlir::UnitAttr untiedAttr;
};

struct UseDeviceClauseOps {
  llvm::SmallVector<mlir::Value> useDevicePtrVars;
  llvm::SmallVector<mlir::Value> useDeviceAddrVars;
  llvm::SmallVector<mlir::Type> useDeviceTypes;
  llvm::SmallVector<mlir::Location> useDeviceLocs;
  llvm::SmallVector<const Fortran::semantics::Symbol *> useDeviceSymbols;
};

//===----------------------------------------------------------------------===//
// Structures defining clause operands associated with each OpenMP leaf
// construct.
//
// These mirror the arguments expected by the corresponding OpenMP MLIR ops.
//===----------------------------------------------------------------------===//

namespace detail {
template <typename... Mixins>
struct Clauses : public Mixins... {};
} // namespace detail

using CriticalClauseOps = detail::Clauses<HintClauseOps>;

// TODO `indirect` clause.
using DeclareTargetClauseOps =
    detail::Clauses<DeviceTypeClauseOps, EnterLinkToClauseOps>;

using DistributeClauseOps =
    detail::Clauses<AllocateClauseOps, DistScheduleClauseOps, OrderClauseOps,
                    PrivateClauseOps>;

// TODO `filter` clause.
using MaskedClauseOps = detail::Clauses<>;

using MasterClauseOps = detail::Clauses<>;

// TODO `doacross` clause.
using OrderedOpClauseOps = detail::Clauses<>;

using OrderedRegionClauseOps = detail::Clauses<ParallelizationLevelClauseOps>;

using ParallelClauseOps =
    detail::Clauses<AllocateClauseOps, IfClauseOps, NumThreadsClauseOps,
                    PrivateClauseOps, ProcBindClauseOps, ReductionClauseOps>;

using SectionsClauseOps = detail::Clauses<AllocateClauseOps, NowaitClauseOps,
                                          PrivateClauseOps, ReductionClauseOps>;

// TODO `linear` clause.
using SimdLoopClauseOps =
    detail::Clauses<AlignedClauseOps, CollapseClauseOps, IfClauseOps,
                    NontemporalClauseOps, OrderClauseOps, PrivateClauseOps,
                    ReductionClauseOps, SafelenClauseOps, SimdlenClauseOps>;

using SingleClauseOps = detail::Clauses<AllocateClauseOps, CopyprivateClauseOps,
                                        NowaitClauseOps, PrivateClauseOps>;

// TODO `defaultmap`, `has_device_addr`, `is_device_ptr`, `uses_allocators`
// clauses.
using TargetClauseOps =
    detail::Clauses<AllocateClauseOps, DependClauseOps, DeviceClauseOps,
                    IfClauseOps, InReductionClauseOps, MapClauseOps,
                    NowaitClauseOps, PrivateClauseOps, TargetReductionClauseOps,
                    ThreadLimitClauseOps>;

using TargetDataClauseOps = detail::Clauses<DeviceClauseOps, IfClauseOps,
                                            MapClauseOps, UseDeviceClauseOps>;

using TargetEnterExitUpdateDataClauseOps =
    detail::Clauses<DependClauseOps, DeviceClauseOps, IfClauseOps, MapClauseOps,
                    NowaitClauseOps>;

// TODO `affinity`, `detach` clauses.
using TaskClauseOps =
    detail::Clauses<AllocateClauseOps, DependClauseOps, FinalClauseOps,
                    IfClauseOps, InReductionClauseOps, MergeableClauseOps,
                    PriorityClauseOps, PrivateClauseOps, UntiedClauseOps>;

using TaskgroupClauseOps =
    detail::Clauses<AllocateClauseOps, TaskReductionClauseOps>;

using TaskloopClauseOps =
    detail::Clauses<AllocateClauseOps, CollapseClauseOps, FinalClauseOps,
                    GrainsizeClauseOps, IfClauseOps, InReductionClauseOps,
                    MergeableClauseOps, NogroupClauseOps, NumTasksClauseOps,
                    PriorityClauseOps, PrivateClauseOps, ReductionClauseOps,
                    UntiedClauseOps>;

using TaskwaitClauseOps = detail::Clauses<DependClauseOps, NowaitClauseOps>;

using TeamsClauseOps =
    detail::Clauses<AllocateClauseOps, IfClauseOps, NumTeamsClauseOps,
                    PrivateClauseOps, ReductionClauseOps, ThreadLimitClauseOps>;

using WsloopClauseOps =
    detail::Clauses<AllocateClauseOps, CollapseClauseOps, LinearClauseOps,
                    NowaitClauseOps, OrderClauseOps, OrderedClauseOps,
                    PrivateClauseOps, ReductionClauseOps, ScheduleClauseOps>;

} // namespace omp
} // namespace lower
} // namespace Fortran

#endif // FORTRAN_LOWER_OPENMP_CLAUSEOPERANDS_H
