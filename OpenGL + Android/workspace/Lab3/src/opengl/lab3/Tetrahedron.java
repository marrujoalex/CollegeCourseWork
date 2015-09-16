package opengl.lab3;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import javax.microedition.khronos.opengles.GL10;

public class Tetrahedron {
  private FloatBuffer vertexBuffer; 		// buffer holding vertices
  private ByteBuffer[] faceIndexBuffer = new ByteBuffer[4]; // buffer holding faces
  private FloatBuffer[] colorBuffer = new FloatBuffer[4]; // buffer holding colors

  private final int nfaces = 4;    //number of faces in object
  //Vertices
  float vertices[] = new float[] {
		  0.0f,0.8f,0.0f,
		  0.8f,0.0f,0.8f,
		  0.8f,0.0f,-0.8f,
		  -0.8f,0.0f,-0.8f
  };
  
  //Faces
  byte faceIndices[][] = {
		  {0,1,2},
		  {2,3,0},
		  {0,1,3},
		  {3,2,1}
  };
    
  public Tetrahedron() {
	// a float has 4 bytes so we allocate for each coordinate 4 bytes
	ByteBuffer byteBuffer = ByteBuffer.allocateDirect(this.vertices.length * 4);
	byteBuffer.order(ByteOrder.nativeOrder());
	vertexBuffer = byteBuffer.asFloatBuffer();
	vertexBuffer.put(vertices);
	vertexBuffer.position(0);
	for(int i = 0; i < nfaces; i++){
	  faceIndexBuffer[i] = ByteBuffer.allocateDirect(this.faceIndices[i].length);
	  faceIndexBuffer[i].put( faceIndices[i] );
	  faceIndexBuffer[i].position(0);
	}
  }

  private void setColor ( GL10 gl,  int i )
  {
     float R = (float) (i % 3) / 3;  
     float G = (float) (i % 4) / 4;  
     float B = (float) (i % 5) / 5;  
     gl.glColor4f( R, G, B, 0 );
 
  }  
  public void draw(GL10 gl) {
	gl.glFrontFace(GL10.GL_CW);
	gl.glVertexPointer(3, GL10.GL_FLOAT, 0, vertexBuffer);
	for(int i = 0; i < nfaces; i++){
 	  setColor ( gl, i );
	  gl.glDrawElements(GL10.GL_TRIANGLES, faceIndexBuffer[i].limit(), 
			       GL10.GL_UNSIGNED_BYTE, faceIndexBuffer[i]);
    }
  }
}
