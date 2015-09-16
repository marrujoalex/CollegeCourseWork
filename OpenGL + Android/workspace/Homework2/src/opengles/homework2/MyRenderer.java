package opengles.homework2;

import android.content.Context;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.opengl.Matrix;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class MyRenderer implements GLSurfaceView.Renderer {

  private Triangle triangle;
  private Context context;
  //private Square square;
  float mVMatrix[] = new float[16];
  float projMatrix[] = new float[16];
  float mMVPMatrix[] = new float[16];
  private int muMVPMatrixHandle;
  private int program;
  private float angleZ= 0.1f;

  public MyRenderer( Context context0 )
  {
         context = context0;
  }

  
  public void onSurfaceCreated(GL10 unused, EGLConfig config) {
    // Set the background frame color
    GLES20.glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    muMVPMatrixHandle = GLES20.glGetUniformLocation(program, "uMVPMatrix");
    
    Matrix.setLookAtM(mVMatrix, 0, 0.0f, 0.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    // construct a triangle object
    triangle = new Triangle( context );
    //construct a square object
    //square = new Square( context );
  }

  public void onDrawFrame(GL10 unused) {
    // Redraw background color
    GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT);
    float mViewMatrix[] = new float [16];
    Matrix.rotateM (mVMatrix, 0, angleZ, 1,1,1);
    Matrix.multiplyMM(mMVPMatrix, 0, projMatrix, 0, mVMatrix, 0);
    if ( angleZ > 360 ) angleZ = 0;
    GLES20.glUniformMatrix4fv(muMVPMatrixHandle, 1, false, mMVPMatrix, 0);
    
    triangle.draw( mMVPMatrix );
    //square.draw( mMVPMatrix );
  }

  public void onSurfaceChanged(GL10 unused, int width, int height) {
     GLES20.glViewport(0, 0, width, height);

     float ratio = (float) width / height;
     Matrix.frustumM(projMatrix, 0, -ratio, ratio, -1, 1, 3, 7);
  }
}