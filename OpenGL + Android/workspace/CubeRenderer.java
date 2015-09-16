package opengl.cube;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.opengl.GLSurfaceView;
import android.opengl.GLU;
import android.opengl.GLUtils;
import android.os.SystemClock;
import android.view.MotionEvent;
  
  public class CubeRenderer implements GLSurfaceView.Renderer {
   
    public float angle = 0.0f;
    private Cube cube = new Cube();
	private Square square = new Square();
	private Context context;
	            
    public CubeRenderer ( Context context0 )
    {
	   context = context0;
    }

    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        // Set the background frame color to grey
        gl.glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        // Do not render back faces
        gl.glEnable( GL10.GL_CULL_FACE );
        gl.glCullFace ( GL10.GL_BACK );
        //square.initTexture(gl, context);
        cube.initTexture(gl, context);
        gl.glEnable(GL10.GL_TEXTURE_2D); 
    }
    
    public void onDrawFrame(GL10 gl) {
        // Redraw background color
        gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);
        // Set GL_MODELVIEW transformation mode
        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();   // Reset the matrix to identity matrix
          
        // Move objects away from view point to observe
        gl.glTranslatef(0.0f, 0.0f, -10.0f);
        // Rotate about a diagonal of cube 
        gl.glRotatef(angle, 1.0f, 1.0f, 1.0f);
        // Draw the cube    
        cube.draw(gl);
    //    square.draw( gl );
           
        gl.glLoadIdentity();   // Reset matrix                                    
            
     }
    
    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        gl.glViewport(0, 0, width, height);
        gl.glMatrixMode(GL10.GL_PROJECTION);
        gl.glLoadIdentity();  // Reset projection matrix
        // Setup viewing volume
        GLU.gluPerspective(gl, 45.0f, (float)width / (float)height, 0.1f, 100.0f);
        gl.glViewport(0, 0, width, height);

        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();  // Reset transformation matrix
    }
    /*
    private void initShapes(){        
        float vertices[] = {
            // (x, y, z) of triangle
            -0.6f, -0.5f, 0,
             0.6f, -0.5f, 0,
             0.0f,  0.5f, 0
        }; 
        
        // initialize vertex Buffer for triangle  
        // argument=(# of coordinate values * 4 bytes per float)
        ByteBuffer vbb = ByteBuffer.allocateDirect(vertices.length * 4); 
        // use the device hardware's native byte order
        vbb.order(ByteOrder.nativeOrder());
        // create a floating point buffer from the ByteBuffer
        triangle = vbb.asFloatBuffer();  
        // add the coordinates to the FloatBuffer
        triangle.put(vertices);    
        // set the buffer to read the first vertex coordinates    
        triangle.position(0);            
    }*/
}

  class Cube {
      
	    private FloatBuffer vertexBuffer;
	    private FloatBuffer colorBuffer;
	    private ByteBuffer  indexBuffer;
	    private FloatBuffer textureBuffer;  // buffer holding the texture coordinates
	    private int[] texHandles = new int[12];
	    private final int nFaces = 4;

	    // Coordinates of 8 vertices of 6 cube faces 
	    private float vertices[] = {
	                                -1.0f, -1.0f, -1.0f,
	                                1.0f, -1.0f, -1.0f,
	                                1.0f,  1.0f, -1.0f,
	                                -1.0f, 1.0f, -1.0f
	                                };
	    private float texture[] = {         
	            // Mapping coordinates for the vertices
	  	       1.0f, 1.0f,             // bottom left     (t0)  
	  	       0.0f, 1.0f,             // bottom right    (t1)
	  	       0.5f, 0.0f,             // top left        (t2)
	  	     //  0.0f, 0.0f,             // top right       (t3)
	  	       
	  	       0.0f, 1.0f,             // bottom left     (t0)  
	  	       1.0f, 1.0f,             // bottom right    (t1)
	  	       0.5f, 0.0f,             // top left        (t2)
	  	   //    1.0f, 0.0f,             // top right       (t3)	  	       	  	       
	    };

	    // Colors of vertices (not used if using texture):
	    private float colors[] = {
                0.0f,  1.0f,  0.0f,  1.0f,
                0.0f,  1.0f,  0.0f,  1.0f,
                1.0f,  0.5f,  0.0f,  1.0f,
                1.0f,  0.5f,  0.0f,  1.0f
             };
	
	    // indices of 12 triangles ( 6 squares ) in GL_CCW
	    // using coordinates of vertices[] array 
	    private byte indices[] = {
                5, 4, 0, 1, 5, 0,
                6, 5, 1, 2, 6, 1,
                7, 6, 2, 3, 7, 2,
                4, 7, 3, 0, 4, 3
                };
	                
	    public Cube() {
	       // initialize vertex Buffer for cube  
	       // argument=(# of coordinate values * 4 bytes per float)
	       ByteBuffer byteBuf = ByteBuffer.allocateDirect(vertices.length * 4);
	       byteBuf.order(ByteOrder.nativeOrder());
	       // create a floating point buffer from the ByteBuffer
	       vertexBuffer = byteBuf.asFloatBuffer();
	       // add the coordinates to the FloatBuffer
	       vertexBuffer.put(vertices);
	       // set the buffer to read the first vertex coordinates 
	       vertexBuffer.position(0);
	
	       /*
	       // Do the same to color values 
	       byteBuf = ByteBuffer.allocateDirect(colors.length * 4);
	       byteBuf.order(ByteOrder.nativeOrder());
	       colorBuffer = byteBuf.asFloatBuffer();
	       colorBuffer.put(colors);
	       colorBuffer.position(0);
	       */
           byteBuf = ByteBuffer.allocateDirect(texture.length * 4);
           byteBuf.order(ByteOrder.nativeOrder());
           textureBuffer = byteBuf.asFloatBuffer();
           textureBuffer.put(texture);
           textureBuffer.position(0);
       
	       // indices are integer
	       indexBuffer = ByteBuffer.allocateDirect(indices.length);
	       indexBuffer.put(indices);
	       indexBuffer.position(0);
	    }
	    
	    public void initTexture(GL10 gl, Context context) {
		    // loading texture
		    //Bitmap bitmap = BitmapFactory.decodeResource(context.getResources(),
		      //      R.drawable.catherine);
		    // generate one texture pointer
		    gl.glGenTextures(nFaces, texHandles, 0);
		    // ...and bind it to our array
		    for ( int i = 0; i < nFaces; i++ ){
		    	  // loading texture
			    Bitmap bitmap = BitmapFactory.decodeResource(context.getResources(),
			            R.drawable.catherine);
		      gl.glBindTexture(GL10.GL_TEXTURE_2D, texHandles[i]);
		      // create nearest filtered texture
		      gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_NEAREST);
		      gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MAG_FILTER, GL10.GL_LINEAR);
		      // Use Android GLUtils to specify a two-dimensional texture image from our bitmap
		      GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, bitmap, 0);
		      bitmap.recycle();
	       }
		    // Clean up
		    //bitmap.recycle();
		}

	    // Typical drawing routine using vertex array
	    public void draw(GL10 gl) { 
	       // Vertices of a front face are in counterclockwise order 
	       gl.glFrontFace(GL10.GL_CCW);
	            
	       gl.glVertexPointer(3, GL10.GL_FLOAT, 0, vertexBuffer);
	 //      gl.glColorPointer(4, GL10.GL_FLOAT, 0, colorBuffer);
	       for ( int i = 0; i < nFaces; i++)
	         gl.glBindTexture(GL10.GL_TEXTURE_2D, texHandles[i]);
	            
	       gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, textureBuffer);
	       gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
	       gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
	    //   gl.glEnableClientState(GL10.GL_COLOR_ARRAY);
	             
	       gl.glDrawElements(GL10.GL_TRIANGLES, 36, GL10.GL_UNSIGNED_BYTE, 
	                            indexBuffer);
	                
	       gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
	    //   gl.glDisableClientState(GL10.GL_COLOR_ARRAY);
	       gl.glDisableClientState(GL10.GL_TEXTURE_COORD_ARRAY);       
	    }
	}
  
class Square {
  private FloatBuffer vertexBuffer;   // buffer holding the vertices
  private FloatBuffer textureBuffer;  // buffer holding the texture coordinates
  private float vertices[] = {
	            -1.0f, -1.0f,  1.0f,        // V0 - bottom left
	            1.0f, -1.0f,  1.0f,        // V1 - bottom right
	            0.0f,  1.0f,  1.0f,        // V2 - top 
//	            1.0f,  1.0f,  1.0f         // V3 - top right
	    };

  private float texture[] = {         
          // Mapping coordinates for the vertices
	       0.0f, 1.0f,             // bottom left     (t0)  
	       1.0f, 1.0f,             // bottom right    (t1)
	       0.5f, 1.0f,             // top             (t2)
//	       1.0f, 0.0f,             // top right       (t3)
  };
  private int[] texHandles = new int[1];

  public Square() {
	  
	      ByteBuffer byteBuffer = ByteBuffer.allocateDirect(vertices.length * 4); 	  
	      byteBuffer.order(ByteOrder.nativeOrder());
	      vertexBuffer = byteBuffer.asFloatBuffer();	  
	      vertexBuffer.put(vertices);
	      vertexBuffer.position(0);
	      
	      byteBuffer = ByteBuffer.allocateDirect(texture.length * 4);
	      byteBuffer.order(ByteOrder.nativeOrder());
	      textureBuffer = byteBuffer.asFloatBuffer();
	      textureBuffer.put(texture);
	      textureBuffer.position(0);
	  }
  
  public void initTexture(GL10 gl, Context context) {
	    // loading texture
	    Bitmap bitmap = BitmapFactory.decodeResource(context.getResources(),
	            R.drawable.catherine);
	    // generate one texture pointer
	    gl.glGenTextures(1, texHandles, 0);
	    // ...and bind it to our array
	    gl.glBindTexture(GL10.GL_TEXTURE_2D, texHandles[0]);
	    // create nearest filtered texture
	    gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_NEAREST);
	    gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MAG_FILTER, GL10.GL_LINEAR);
	    // Use Android GLUtils to specify a two-dimensional texture image from our bitmap
	    GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, bitmap, 0);
	    // Clean up
	    bitmap.recycle();
	}

  
  public void draw(GL10 gl) { 
      // Vertices of a front face are in counterclockwise order 
      gl.glFrontFace(GL10.GL_CCW);
      gl.glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
      // bind the previously generated texture
       gl.glBindTexture(GL10.GL_TEXTURE_2D, texHandles[0]);

      gl.glVertexPointer(3, GL10.GL_FLOAT, 0, vertexBuffer);
      gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, textureBuffer);
      gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
      gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
      
      gl.glDrawArrays(GL10.GL_TRIANGLE_STRIP, 0, vertices.length / 3);       
               
       gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
       gl.glDisableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
   }
}
