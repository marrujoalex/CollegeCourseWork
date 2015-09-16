package opengl.lab3;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;
import android.opengl.GLSurfaceView.Renderer;

public class TetrahedronRenderer implements Renderer 
{
  GL10 gl;
  Tetrahedron tetrahedron = new Tetrahedron();
  private float anglex; 
  private float anglez; 
  private final int nfaces = 4;
  //@Override 
  //Refresh automatically
  public void onDrawFrame(GL10 gl) 
  {
	gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);
	gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
	gl.glEnableClientState(GL10.GL_COLOR_ARRAY);
	gl.glMatrixMode(GL10.GL_MODELVIEW);
	gl.glLoadIdentity();
	gl.glTranslatef(0.0f, 0.0f, -3.0f); 
	gl.glRotatef( anglex, 1.0f, 0.0f, 0.0f ); // Rotate about  x-axis
	gl.glRotatef( anglez, 0.0f, 0.0f, 1.0f); // Rotate about z-axis
	tetrahedron.draw(gl);
	anglex += 1.0f;
	anglez += 2.0f;
	gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
	gl.glDisableClientState(GL10.GL_COLOR_ARRAY);
  }
  

  public void onSurfaceChanged(GL10 gl, int width, int height) 
  {
    	gl.glViewport(0, 0, width, height);
  	float ratio = (float) width / height;
  	gl.glMatrixMode(GL10.GL_PROJECTION);
  	gl.glLoadIdentity();
  	gl.glFrustumf(-ratio, ratio, -1, 1, 1, 10);
  }
  
  public void onSurfaceCreated(GL10 gl, EGLConfig config) 
  {
  	gl.glDisable(GL10.GL_DITHER);
  	gl.glHint(GL10.GL_PERSPECTIVE_CORRECTION_HINT, GL10.GL_FASTEST);
  	gl.glClearColor(1, 1, 1, 0);
  	gl.glEnable(GL10.GL_CULL_FACE);
  	gl.glShadeModel(GL10.GL_SMOOTH);
  	gl.glEnable(GL10.GL_DEPTH_TEST);
  }
}