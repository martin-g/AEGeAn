/**

Copyright (c) 2010-2015, Daniel S. Standage and CONTRIBUTORS

The AEGeAn Toolkit is distributed under the ISC License. See
the 'LICENSE' file in the AEGeAn source code distribution or
online at https://github.com/standage/AEGeAn/blob/master/LICENSE.

**/

#ifndef AEGEAN_LOCUS_REFINE_STREAM
#define AEGEAN_LOCUS_REFINE_STREAM

#include "extended/node_stream_api.h"
#include "AgnUnitTest.h"

/**
 * @class AgnLocusRefineStream
 *
 * Implements the ``GtNodeStream`` interface. By default the ``AgnLocusStream``
 * class will group any and all overlapping features of interest together in the
 * same iLocus. The ``AgnLocusRefineStream`` class can be used to post-process
 * ``AgnLocusStream`` output to accommodate a more flexible handling of
 * overlapping features, such as requiring CDS overlap for grouping genes
 * together or creating distinct iLoci for genes within the introns of other
 * genes.
 */
typedef struct AgnLocusRefineStream AgnLocusRefineStream;

/**
 * @function Class constructor.
 */
GtNodeStream *agn_locus_refine_stream_new(GtNodeStream *in_stream,
                                          GtUword delta, GtUword minoverlap,
                                          bool by_cds);

/**
 * @function Loci created by this stream are assigned an ID with a serial
 * number. The default format is 'locus%lu' (that is, locus1, locus2, etc).
 * Use this function to override the default ID format.
 */
void agn_locus_refine_stream_set_idformat(AgnLocusRefineStream *stream,
                                          const char *format);

/**
 * @function Run unit tests for this class. Returns true if all tests passed.
 */
bool agn_locus_refine_stream_unit_test(AgnUnitTest *test);

#endif
