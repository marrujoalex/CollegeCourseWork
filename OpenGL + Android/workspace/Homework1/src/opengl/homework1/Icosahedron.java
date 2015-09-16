package opengl.homework1;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import javax.microedition.khronos.opengles.GL10;

public class Icosahedron {
  private FloatBuffer vertexBuffer; 		// buffer holding vertices
  private ByteBuffer[] faceIndexBuffer = new ByteBuffer[20]; // buffer holding faces
  private FloatBuffer[] colorBuffer = new FloatBuffer[20]; // buffer holding colors

  private final int nfaces = 20;    //number of faces in object
  //Vertices
  float vertices[] = new float[] {
	    0f, -0.525731f, 0.850651f,             // vertices[0]
        0.850651f, 0f, 0.525731f,              // vertices[1]
        0.850651f, 0f, -0.525731f,             // vertices[2]
        -0.850651f, 0f, -0.525731f,            // vertices[3]
        -0.850651f, 0f, 0.525731f,             // vertices[4]
        -0.525731f, 0.850651f, 0f,             // vertices[5]
        0.525731f, 0.850651f, 0f,              // vertices[6]
        0.525731f, -0.850651f, 0f,             // vertices[7]
        -0.525731f, -0.850651f, 0f,            // vertices[8]
        0f, -0.525731f, -0.850651f,            // vertices[9]
        0f, 0.525731f, -0.850651f,             // vertices[10]
        0f, 0.525731f, 0.850651f               // vertices[11]
  };
  
  //Faces
  byte faceIndices[][] = {
	{1, 2, 6},
        {1, 7, 2},
        {3, 4, 5},
        {4, 3, 8},
        {6, 5, 11},
        {5, 6, 10},
        {9, 10, 2},
        {10, 9, 3},
        {7, 8, 9},
        {8, 7, 0},
        {11, 0, 1},
        {0, 11, 4},
        {6, 2, 10},
        {1, 6, 11},
        {3, 5, 10},
        {5, 4, 11},
        {2, 7, 9},
        {7, 1, 0},
        {3, 9, 8},
        {4, 8, 0}
  };
    
  public Icosahedron() {
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
