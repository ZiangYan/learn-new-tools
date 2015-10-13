#include "mex.h"

/*
 * addArray.c 
 *
 * Add each column by column index.
 *
 * The calling syntax is:
 *
 *		outMatrix = addArray(inMatrix)
 *
 * This is a MEX file for MATLAB.
 */


void addArray(double *in, double *out, mwSize numCols, mwSize numRows)
{
    mwSize i, j;
    for (i = 0; i < numRows; ++i){
        for (j = 0; j < numCols; ++j){
            out[i + numRows * j] = in[i + numRows * j] + j;
        }
    }
    
}

/* The gateway function */
void mexFunction(int nlhs, mxArray *plhs[],
        int nrhs, const mxArray *prhs[])
{
    
    double *inMatrix;       /* MxN input matrix */
    double *outMatrix;       /* MxN input matrix */
    
    mwSize numRows;           /* size of matrix */
    mwSize numCols;           /* size of matrix */
    
    if(nrhs != 1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs",
                "Two inputs required.");
    }
    if(nlhs != 1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs",
                "One output required.");
    }
    if( !mxIsDouble(prhs[0]) ||
            mxIsComplex(prhs[0])) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notDouble",
                "Input matrix must be type double.");
    }
    /* create a pointer to the real data in the input matrix  */
    inMatrix = mxGetPr(prhs[0]);
    /* get dimensions of the input matrix */
    numCols = mxGetN(prhs[0]);
    numRows = mxGetM(prhs[0]);
    /* create the output matrix */
    plhs[0] = mxCreateDoubleMatrix(numRows, numCols, mxREAL);
    /* get a pointer to the real data in the output matrix */
    outMatrix = mxGetPr(plhs[0]);
    /* call the computational routine */
    addArray(inMatrix, outMatrix, numCols, numRows);
}
